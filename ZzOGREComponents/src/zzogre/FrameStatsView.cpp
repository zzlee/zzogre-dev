/*
 * FrameStatsView.cpp
 *
 *  Created on: 2013/4/10
 *      Author: SUCHEN
 */

#include "FrameStatsView.h"

#include <OgreCamera.h>
using namespace Ogre;

#include <zzogre/ZzOGRE.h>
#include <zzogre/SceneNodes.h>

#include <boost/format.hpp>
using namespace boost;

using namespace std;

namespace zzogre {

ZZOGRE_COMPONENT_REGISTER(FrameStatsView);

FrameStatsView::FrameStatsView() :
		mRenderTarget(NULL), mCurrFPS(NULL), mAvgFPS(NULL), mWorstFPS(NULL), mBestFPS(
				NULL), mTriCount(NULL), mBatchCount(NULL) {
	enableFrameEvent(FET_Started);
}

FrameStatsView::~FrameStatsView() {
}

void FrameStatsView::onEnable() {
	Camera* camera = getAttachedObject<Camera>();
	if (!camera)
		HR(E_POINTER);

	Viewport* viewport = camera->getViewport();

	// setup GUI
	Gorilla::Screen* screen = _Gui3D->createScreen(viewport, "completeGUIDemo",
			parent.get()->getName() + "/Screen");
	mPanel.reset(
			new Gui3D::ScreenPanel(_Gui3D, screen,
					Ogre::Vector2(0, viewport->getActualHeight() - 180),
					Ogre::Vector2(250, 180), "dejavu",
					parent.get()->getName() + "/FrameStats"));

	mCurrFPS = mPanel->makeCaption(5, 0, 290, 30, "Current FPS: ");
	mAvgFPS = mPanel->makeCaption(5, 30, 290, 30, "Average FPS: ");
	mWorstFPS = mPanel->makeCaption(5, 60, 290, 30, "Worst FPS: ");
	mBestFPS = mPanel->makeCaption(5, 90, 290, 30, "Best FPS: ");
	mTriCount = mPanel->makeCaption(5, 120, 290, 30, "Triangle Count: ");
	mBatchCount = mPanel->makeCaption(5, 150, 290, 30, "Batch Count: ");

	mRenderTarget = camera->getViewport()->getTarget();
}

void FrameStatsView::onDisable() {
	mPanel.reset();
	_Gui3D->destroyScreen(parent.get()->getName() + "/Screen");
}

void FrameStatsView::onFrameStarted() {
	const RenderTarget::FrameStats& stats = mRenderTarget->getStatistics();

	mCurrFPS->text((format("Current FPS: %.2f") % stats.lastFPS).str());
	mAvgFPS->text((format("Average FPS: %.2f") % stats.avgFPS).str());
	mWorstFPS->text((format("Worst FPS: %.2f") % stats.worstFPS).str());
	mBestFPS->text((format("Best FPS: %.2f") % stats.bestFPS).str());
	mTriCount->text((format("Triangle Count: %d") % stats.triangleCount).str());
	mBatchCount->text((format("Batch Count: %d") % stats.batchCount).str());
}

} /* namespace zzogre */
