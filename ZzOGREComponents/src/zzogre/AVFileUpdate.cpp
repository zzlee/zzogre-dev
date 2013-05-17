/*
 * AVFileUpdate.cpp
 *
 *  Created on: 2012/11/30
 *      Author: SUCHEN
 */

#include "AVFileUpdate.h"

#include "zzogre/ZzOGRE.h"
#include "zzogre/FrameEventManager.h"
#include "zzogre/Logger.h"

using namespace std;

#include <zzlab/cv.h>
using namespace zzlab;

#include <boost/bind.hpp>
#include <boost/locale.hpp>
#include <boost/filesystem.hpp>
#include <boost/format.hpp>
using namespace boost;
namespace bf = boost::filesystem;

#include <OgreResourceGroupManager.h>
#include <OgreArchive.h>
using namespace Ogre;

namespace zzogre {

ZZOGRE_COMPONENT_REGISTER(AVFileUpdate);

AVFileUpdate::AVFileUpdate() :
		name("sample.avi"), group("General"), fps(30), hasVideo(false), hasAudio(
				false), mTime(0), mDuration(0), mType(CV_8UC1), mSize(
				(Size_t ) { 0, 0 }) {
//	cout << __PRETTY_FUNCTION__ << endl;

	enableFrameEvent(FET_Started);
}

AVFileUpdate::~AVFileUpdate() {
//	cout << __PRETTY_FUNCTION__ << endl;
}

void AVFileUpdate::onEnable() {
//	cout << __PRETTY_FUNCTION__ << endl;

	HRESULT hr = S_OK;

	if (name.empty() || group.empty())
		return;

	FileInfoListPtr fileInfos = _ResourceGroupManager->findResourceFileInfo(
			group, name);
	if (fileInfos->empty())
		return;

	const FileInfo& fileInfo = (*fileInfos)[0];
	bf::path filepath = bf::path(fileInfo.archive->getName())
			/ fileInfo.filename;
	LOGI(format("Prepare to load %s...") % filepath.string());

	wstring filename = locale::conv::utf_to_utf<wchar_t>(
			filepath.string().c_str());

	hr = _ZzCOM->CreateLAVMediaPlayer((ILAVMediaPlayer**) &mMediaPlayer), HR(hr);
	hr = mMediaPlayer->put_SyncSource(_Clock.get()), HR(hr);

	BSTR bstr = SysAllocString(filename.c_str());
	hr = mMediaPlayer->put_Movie(bstr), HR(hr);
	SysFreeString(bstr);

	hr = mMediaPlayer->get_HasAudio(&hasAudio), HR(hr);
	hr = mMediaPlayer->get_HasVideo(&hasVideo), HR(hr);
	ZzOgreAssert(hasVideo == VARIANT_TRUE, "No video?");

	Size_t size_;
	hr = mMediaPlayer->get_Size(&size_), HR(hr);
	size(size_);

	ImageType_t type_;
	hr = mMediaPlayer->get_ImageType(&type_), HR(hr);
	ZzOgreAssert(type_ == ImageType_YV12, "Image type is not suppoerted");
	type(type_);

	hr = mMediaPlayer->QueryInterface(IID_IMediaPlayer, (void**) &player), HR(hr);
	hr = player->QueryInterface(IID_IFilterGraph, (void**) &graph), HR(hr);
	hr = graph->QueryInterface(IID_IMediaSeeking, (void**) &seeking), HR(hr);
	hr = seeking->SetTimeFormat(&TIME_FORMAT_MEDIA_TIME), HR(hr);

	mSize = size_;
	mType = toCvMatType(type_, &mSize);

	mTime = 0;
	mDuration = 1 / (fps * 2);

	LOGI(format("%s loaded.") % filepath.string());
}

void AVFileUpdate::onDisable() {
//	cout << __PRETTY_FUNCTION__ << endl;

	player.reset();
	graph.reset();
	seeking.reset();
	mMediaPlayer.reset();

//	cout << '~' << __PRETTY_FUNCTION__ << endl;
}

void AVFileUpdate::onFrameStarted() {
	HRESULT hr = S_OK;

	mTime += _FrameEvent.timeSinceLastFrame;
	if (mTime > mDuration) {
		mTime -= mDuration;

		ImageInfo_t src;
		hr = mMediaPlayer->LockImage(&src), HR(hr);
		if (src.Pointer) {
			output(
					cv::Mat(mSize.Height, mSize.Width, mType,
							(void*) src.Pointer, src.Step));
			hr = mMediaPlayer->UnlockImage(), HR(hr);
		}
	}
}

} /* namespace zzogre */
