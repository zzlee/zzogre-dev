/*
 * ZzOgre.cpp
 *
 *  Created on: 2013/4/1
 *      Author: SUCHEN
 */

#include "ZzOGRE.h"

using namespace std;

#include <OgreResourceBackgroundQueue.h>
#include <OgreD3D9RenderSystem.h>
#include <OgreD3D9DeviceManager.h>
#include <OgreD3D9RenderWindow.h>
#include <OgreString.h>
#include <OgreStringConverter.h>
using namespace Ogre;

#include <boost/algorithm/string.hpp>
using namespace boost;
using namespace boost::filesystem;

#include "SceneNodes.h"

namespace zzogre {

Ogre::Root* _Root = NULL;
Ogre::RenderSystem* _RenderSystem = NULL;
Ogre::ResourceGroupManager* _ResourceGroupManager = NULL;
Ogre::ArchiveManager* _ArchiveManager = NULL;
Ogre::CompositorManager* _CompositorManager = NULL;
Ogre::ControllerManager* _ControllerManager = NULL;
Ogre::GpuProgramManager* _GpuProgramManager = NULL;
Ogre::HardwareBufferManager* _HardwareBufferManager = NULL;
Ogre::HighLevelGpuProgramManager* _HighLevelGpuProgramManager = NULL;
Ogre::LogManager* _LogManager = NULL;
Ogre::MaterialManager* _MaterialManager = NULL;
Ogre::MeshManager* _MeshManager = NULL;
Ogre::OverlayManager* _OverlayManager = NULL;
Ogre::ParticleSystemManager* _ParticleSystemManager = NULL;
Ogre::Profiler* _Profiler = NULL;
Ogre::ResourceBackgroundQueue* _ResourceBackgroundQueue = NULL;
Ogre::SceneManagerEnumerator* _SceneManagerEnumerator = NULL;
Ogre::ShadowTextureManager* _ShadowTextureManager = NULL;
Ogre::SkeletonManager* _SkeletonManager = NULL;
Ogre::TextureManager* _TextureManager = NULL;
Ogre::SceneManager* _SceneManager = NULL;

OISRenderWindowPtr _Window;
std::vector<OISRenderWindowPtr> _Windows;

Gui3D::Gui3D* _Gui3D = NULL;

Ogre::AxisAlignedBox EmptyAABB(0, 0, 0, 0, 0, 0);
Ogre::Rect EmptyRect(0, 0, 0, 0);

void cacheSingletons() {
	_ArchiveManager = Ogre::ArchiveManager::getSingletonPtr();
	_LogManager = Ogre::LogManager::getSingletonPtr();
	_ResourceGroupManager = Ogre::ResourceGroupManager::getSingletonPtr();
	_CompositorManager = Ogre::CompositorManager::getSingletonPtr();
	_ControllerManager = Ogre::ControllerManager::getSingletonPtr();
	_GpuProgramManager = Ogre::GpuProgramManager::getSingletonPtr();
	_HardwareBufferManager = Ogre::HardwareBufferManager::getSingletonPtr();
	_HighLevelGpuProgramManager =
			Ogre::HighLevelGpuProgramManager::getSingletonPtr();
	_MaterialManager = Ogre::MaterialManager::getSingletonPtr();
	_MeshManager = Ogre::MeshManager::getSingletonPtr();
	_OverlayManager = Ogre::OverlayManager::getSingletonPtr();
	_ParticleSystemManager = Ogre::ParticleSystemManager::getSingletonPtr();
	_Profiler = Ogre::Profiler::getSingletonPtr();
	_ResourceBackgroundQueue = Ogre::ResourceBackgroundQueue::getSingletonPtr();
	_ResourceGroupManager = Ogre::ResourceGroupManager::getSingletonPtr();
	_SceneManagerEnumerator = Ogre::SceneManagerEnumerator::getSingletonPtr();
	_ShadowTextureManager = Ogre::ShadowTextureManager::getSingletonPtr();
	_SkeletonManager = Ogre::SkeletonManager::getSingletonPtr();
	_TextureManager = Ogre::TextureManager::getSingletonPtr();
}

static void addResourceGroup(const std::string& groupName, path p) {
	_ResourceGroupManager->addResourceLocation(p.string(), "FileSystem",
			groupName);

	directory_iterator end_iter;
	for (directory_iterator i(p); i != end_iter; ++i) {
		file_status status = (*i).status();
		if (is_directory(status)) {
			addResourceGroup(groupName, (*i).path());
		} else if (is_regular_file(status)) {
			if (stricmp(to_lower_copy((*i).path().extension().string()).c_str(),
					".zip") == 0) {
				_ResourceGroupManager->addResourceLocation((*i).path().string(),
						"Zip", groupName);
			}
		}
	}
}

void addResourceGroups(boost::filesystem::path p) {
	directory_iterator end_iter;
	for (directory_iterator i(p); i != end_iter; ++i) {
		if (is_directory((*i).status())) {
			path group = (*i).path();
			addResourceGroup(group.filename().string(), group);
		}
	}
}

void loadAllBehaviors(boost::filesystem::path p) {
	directory_iterator end_iter;
	for (directory_iterator i(p); i != end_iter; ++i) {
		if (is_regular_file((*i).status())) {
			path p = (*i).path();
			if (stricmp(to_lower_copy(p.extension().string()).c_str(), ".dll")
					== 0) {
				_Root->loadPlugin(p.string());
			}
		}
	}
}

void setRenderWindowActive(Ogre::RenderWindow* rw) {
	Ogre::D3D9RenderWindow* renderWindow =
			dynamic_cast<Ogre::D3D9RenderWindow*>(rw);
	ZzOgreAssert(renderWindow, "D3D9 render window required");

	Ogre::D3D9RenderSystem* renderSystem =
			dynamic_cast<Ogre::D3D9RenderSystem*>(_RenderSystem);
	ZzOgreAssert(renderSystem, "D3D9 render system required");

	renderSystem->getDeviceManager()->setActiveDevice(
			renderWindow->getDevice());
}

RenderWindowResourcesClosure::RenderWindowResourcesClosure(
		Ogre::MovableObject* movableObject) {
	if (movableObject) {
		Ogre::Any anyDeviceName = SceneNodes::getDeviceResource(movableObject);
		if (anyDeviceName.isEmpty())
			inClosure = false;
		else {
			beginRenderWindowResources(
					dynamic_cast<Ogre::RenderWindow*>(_Root->getRenderTarget(
							Ogre::any_cast<std::string>(anyDeviceName))));
			inClosure = true;
		}
	} else
		inClosure = false;
}

Ogre::String toString(const Euler& val) {
	stringstream stream;
	stream << val.getYaw().valueDegrees() << " "
			<< val.getPitch().valueDegrees() << " "
			<< val.getRoll().valueDegrees();
	return stream.str();
}

Euler parseEuler(const Ogre::String& val, const Euler& defaultValue) {
	// Split on space
	Ogre::vector<Ogre::String>::type vec = Ogre::StringUtil::split(val);

	if (vec.size() != 3) {
		return defaultValue;
	} else {
		return Euler(StringConverter::parseAngle(vec[0]),
				StringConverter::parseAngle(vec[1]),
				StringConverter::parseAngle(vec[2]));
	}
}

Ogre::String toString(const Ogre::AxisAlignedBox& val) {
	const Vector3& m = val.getMinimum();
	const Vector3& M = val.getMaximum();

	stringstream stream;
	stream << m.x << " " << m.y << " " << m.z << " " << M.x << " " << M.y << " "
			<< M.z;
	return stream.str();
}

Ogre::AxisAlignedBox parseAxisAlignedBox(const Ogre::String& val,
		const Ogre::AxisAlignedBox& defaultValue) {
	// Split on space
	Ogre::vector<Ogre::String>::type vec = Ogre::StringUtil::split(val);

	if (vec.size() != 6) {
		return defaultValue;
	} else {
		return Ogre::AxisAlignedBox(StringConverter::parseReal(vec[0]),
				StringConverter::parseReal(vec[1]),
				StringConverter::parseReal(vec[2]),
				StringConverter::parseReal(vec[3]),
				StringConverter::parseReal(vec[4]),
				StringConverter::parseReal(vec[5]));
	}
}

Ogre::PixelFormat parsePixelFormat(const Ogre::String& val,
		const Ogre::PixelFormat& defaultValue) {
	if (val == "l8")
		return PF_L8;
	else if (val == "l16")
		return PF_L16;
	else if (val == "a8")
		return PF_A8;
	else if (val == "a4l4")
		return PF_A4L4;
	else if (val == "r5g6b5")
		return PF_R5G6B5;
	else if (val == "b5g6r5")
		return PF_B5G6R5;
	else if (val == "r2g2b2")
		return PF_R3G3B2;
	else if (val == "a4r4g4b4")
		return PF_A4R4G4B4;
	else if (val == "a1r5g5b5")
		return PF_A1R5G5B5;
	else if (val == "r8g8b8")
		return PF_R8G8B8;
	else if (val == "b8r8g8")
		return PF_B8G8R8;
	else if (val == "a8r8g8b8")
		return PF_A8R8G8B8;
	else if (val == "a8b8g8r8")
		return PF_A8B8G8R8;
	else if (val == "b8g8r8a8")
		return PF_B8G8R8A8;
	else if (val == "r8g8b8a8")
		return PF_R8G8B8A8;
	else if (val == "x8r8g8b8")
		return PF_X8R8G8B8;
	else if (val == "x8b8g8r8")
		return PF_X8B8G8R8;
	else if (val == "dx1")
		return PF_DXT1;
	else if (val == "dx2")
		return PF_DXT2;
	else if (val == "dx3")
		return PF_DXT3;
	else if (val == "dx4")
		return PF_DXT4;
	else if (val == "dx5")
		return PF_DXT5;
	else if (val == "float16-r")
		return PF_FLOAT16_R;
	else if (val == "float16-rgb")
		return PF_FLOAT16_RGB;
	else if (val == "float16-rgba")
		return PF_FLOAT16_RGBA;
	else if (val == "float32-r")
		return PF_FLOAT32_R;
	else if (val == "float32-rgb")
		return PF_FLOAT32_RGB;
	else if (val == "float32-rgba")
		return PF_FLOAT32_RGBA;
	else if (val == "depth")
		return PF_DEPTH;
	else if (val == "short-rgba")
		return PF_SHORT_RGBA;
	else if (val == "short-gr")
		return PF_SHORT_GR;
	else if (val == "short-rgb")
		return PF_SHORT_RGB;
	else if (val == "r8")
		return PF_R8;
	else if (val == "r8g8")
		return PF_RG8;
	else
		return defaultValue;
}

Ogre::String toString(const Ogre::Rect& val) {
	stringstream stream;
	stream << val.left << " " << val.top << " " << val.right << " "
			<< val.bottom;
	return stream.str();
}

Ogre::Rect parseRect(const Ogre::String& val, const Ogre::Rect& defaultValue) {
	// Split on space
	Ogre::vector<Ogre::String>::type vec = Ogre::StringUtil::split(val);

	if (vec.size() != 4) {
		return defaultValue;
	} else {
		return Ogre::Rect(StringConverter::parseInt(vec[0]),
				StringConverter::parseInt(vec[1]),
				StringConverter::parseInt(vec[2]),
				StringConverter::parseInt(vec[3]));
	}
}

Ogre::String flagsToString(const uint32_t& val) {
	stringstream stream;
	stream << hex << showbase << val;
	return stream.str();
}

uint32_t parseFlags(const Ogre::String& val, const uint32_t& defaultValue) {
	istringstream stream(val);

	uint32_t ret = defaultValue;
	stream >> hex >> ret;

	return ret;
}

Ogre::RenderTarget* getRenderTarget(const Ogre::String& name) {
	// try searching through created render windows
	RenderTarget *pRval = _Root->getRenderTarget(name);

	// if the name doesn't refer to a RenderWindow, try searching for a
	//      RenderTexture
	if (pRval == NULL) {
		try {
			TexturePtr pRtt = _TextureManager->getByName(name);

			// throws exception if not a render target
			if (!pRtt.isNull())
				pRval = pRtt->getBuffer()->getRenderTarget();
		} catch (Exception &e) {
			// do nothing
		}
	}

	return pRval;
}

struct _DefaultPanelColors : public Gui3D::PanelColors
{
	_DefaultPanelColors() {
	    // General
	    transparent = Gorilla::rgb(0, 0, 0, 0);

	    // Panel
	    panelBackgroundSpriteName = "panelBackground";

	    // Button
	    buttonInactiveSpriteName = "buttonInactive";
	    buttonOveredSpriteName = "buttonOvered";
	    buttonNotOveredSpriteName = "buttonNotOvered";
	    buttonClickedSpriteName = "buttonClicked";

	    buttonBackgroundClickedGradientType = Gorilla::Gradient_NorthSouth;
	    buttonBackgroundClickedGradientStart = Gorilla::rgb(255, 255, 255, 200);
	    buttonBackgroundClickedGradientEnd = Gorilla::rgb(255, 255, 255, 170);

	    buttonBackgroundOveredGradientType = Gorilla::Gradient_NorthSouth;
	    buttonBackgroundOveredGradientStart = Gorilla::rgb(255, 255, 255, 128);
	    buttonBackgroundOveredGradientEnd = Gorilla::rgb(255, 255, 255, 100);

	    buttonBackgroundNotOveredGradientType = Gorilla::Gradient_NorthSouth;
	    buttonBackgroundNotOveredGradientStart = Gorilla::rgb(255, 255, 255, 80);
	    buttonBackgroundNotOveredGradientEnd = Gorilla::rgb(255, 255, 255, 50);

	    buttonBackgroundInactiveGradientType = Gorilla::Gradient_NorthSouth;
	    buttonBackgroundInactiveGradientStart = Gorilla::rgb(255, 255, 255, 15);
	    buttonBackgroundInactiveGradientEnd = Gorilla::rgb(255, 255, 255, 5);

	    buttonText = Gorilla::rgb(255, 255, 255, 255);
	    buttonTextInactive = Gorilla::rgb(255, 255, 255, 70);
	    buttonTextSize = 14;

	    buttonBorder = Gorilla::rgb(70, 70, 70, 50);
	    buttonBorderHighlight = Gorilla::rgb(255, 100, 100, 170);
	    buttonBorderInactive = Gorilla::rgb(70, 70, 70, 15);
	    buttonBorderSize = 1;

	    // Checkbox
	    checkboxOveredBackgroundSpriteName = "checkboxOvered";
	    checkboxNotOveredBackgroundSpriteName = "checkboxNotOvered";
	    checkboxCheckedNotOveredBackgroundSpriteName = "checkboxCheckedNotOvered";
	    checkboxCheckedOveredBackgroundSpriteName = "checkboxCheckedOvered";

	    // Combobox
	    comboboxButtonPreviousOveredSpriteName = "comboboxpreviouselementbuttonovered";
	    comboboxButtonPreviousNotOveredSpriteName = "comboboxpreviouselementbuttonnotovered";
	    comboboxButtonPreviousInactiveSpriteName = "comboboxpreviouselementbuttoninactive";

	    comboboxButtonNextOveredSpriteName = "comboboxnextelementbuttonovered";
	    comboboxButtonNextNotOveredSpriteName = "comboboxnextelementbuttonnotovered";
	    comboboxButtonNextInactiveSpriteName = "comboboxnextelementbuttoninactive";

	    comboboxBackgroundGradientType = Gorilla::Gradient_NorthSouth;
	    comboboxBackgroundGradientStart = Gorilla::rgb(255, 255, 255, 0);
	    comboboxBackgroundGradientEnd = Gorilla::rgb(255, 255, 255, 0);

	    comboboxOveredElement = Gorilla::rgb(255, 255, 255, 100);
	    comboboxNotOveredElement = Gorilla::rgb(255, 255, 255, 30);
	    comboboxSelectedElement = Gorilla::rgb(120, 20, 120, 200);

	    comboboxText = Ogre::ColourValue::White;
	    comboboxTextSize = 14;

	    comboboxBorder = Gorilla::rgb(70, 70, 70, 50);
	    comboboxBorderHighlight = Gorilla::rgb(255, 100, 100, 170);
	    comboboxBorderSize = 0;

	    // InlineSelector
	    inlineselectorButtonPreviousOveredSpriteName = "inlineselectorPreviousButtonOvered";
	    inlineselectorButtonPreviousNotOveredSpriteName = "inlineselectorPreviousButtonNotOvered";
	    inlineselectorButtonPreviousInactiveSpriteName = "inlineselectorPreviousButtonInactive";

	    inlineselectorButtonNextOveredSpriteName = "inlineselectorNextButtonOvered";
	    inlineselectorButtonNextNotOveredSpriteName = "inlineselectorNextButtonNotOvered";
	    inlineselectorButtonNextInactiveSpriteName = "inlineselectorNextButtonInactive";

	    inlineselectorBackgroundGradientType = Gorilla::Gradient_NorthSouth;
	    inlineselectorBackgroundGradientStart = transparent;
	    inlineselectorBackgroundGradientEnd = transparent;

	    inlineselectorText = Ogre::ColourValue::White;
	    inlineselectorTextSize = 14;

	    inlineselectorBorder = transparent;
	    inlineselectorBorderHighlight = Gorilla::rgb(255, 100, 100, 170);
	    inlineselectorBorderSize = 1;

	    // Listbox
	    // same value as the combobox
	    listboxButtonPreviousOveredSpriteName = comboboxButtonPreviousOveredSpriteName;
	    listboxButtonPreviousNotOveredSpriteName = comboboxButtonPreviousNotOveredSpriteName;
	    listboxButtonPreviousInactiveSpriteName = comboboxButtonPreviousInactiveSpriteName;

	    listboxButtonNextOveredSpriteName = comboboxButtonNextOveredSpriteName;
	    listboxButtonNextNotOveredSpriteName = comboboxButtonNextNotOveredSpriteName;
	    listboxButtonNextInactiveSpriteName = comboboxButtonNextInactiveSpriteName;

	    listboxBackgroundGradientType = comboboxBackgroundGradientType;
	    listboxBackgroundGradientStart = comboboxBackgroundGradientStart;
	    listboxBackgroundGradientEnd = comboboxBackgroundGradientEnd;

	    listboxOveredElement = comboboxOveredElement;
	    listboxNotOveredElement = comboboxNotOveredElement;
	    listboxOveredSelectedElement = comboboxSelectedElement;
	    listboxNotOveredSelectedElement = comboboxSelectedElement + Gorilla::rgb(0, 0, 0, -50);

	    listboxText = comboboxText;
	    listboxTextSize = 14;

	    listboxBorder = comboboxBorder;
	    listboxBorderHighlight = comboboxBorderHighlight;
	    listboxBorderSize = comboboxBorderSize;

	    // Scrollbar
	    scrollbarCursorOveredSpriteName = "scrollbarOvered";
	    scrollbarCursorNotOveredSpriteName = "scrollbarNotOvered";
	    scrollbarCursorSelectedSpriteName = "scrollbarSelected";

	    scrollbarBackgroundGradientType = Gorilla::Gradient_NorthSouth;
	    scrollbarBackgroundGradientStart = Gorilla::rgb(255, 255, 255, 80);
	    scrollbarBackgroundGradientEnd = Gorilla::rgb(255, 255, 255, 40);

	    scrollbarProgressbarGradientType = Gorilla::Gradient_WestEast;
	    scrollbarProgressbarGradientStart = Gorilla::rgb(120, 20, 120, 40);
	    scrollbarProgressbarGradientEnd = Gorilla::rgb(120, 20, 120, 80);

	    scrollbarText = Ogre::ColourValue::White;
	    scrollbarTextSize = 14;

	    scrollbarBorder = Gorilla::rgb(70, 70, 70, 50);
	    scrollbarBorderHighlight = Gorilla::rgb(255, 100, 100, 170);
	    scrollbarCursorBorder =  Gorilla::rgb(120, 20, 120, 150);
	    scrollbarBorderSize = 1;
	    scrollbarCursorBorderSize = 1;

	    // TextZone
	    textzoneBackgroundOveredGradientType = Gorilla::Gradient_NorthSouth;
	    textzoneBackgroundOveredGradientStart = Gorilla::rgb(255, 255, 255, 128);
	    textzoneBackgroundOveredGradientEnd = Gorilla::rgb(255, 255, 255, 90);

	    textzoneBackgroundNotOveredGradientType = Gorilla::Gradient_NorthSouth;
	    textzoneBackgroundNotOveredGradientStart = Gorilla::rgb(255, 255, 255, 50);
	    textzoneBackgroundNotOveredGradientEnd = Gorilla::rgb(255, 255, 255, 20);

	    textzoneBackgroundSelectedGradientType = Gorilla::Gradient_NorthSouth;
	    textzoneBackgroundSelectedGradientStart = Gorilla::rgb(200, 200, 200, 170);
	    textzoneBackgroundSelectedGradientEnd = Gorilla::rgb(200, 200, 200, 140);

	    textzoneText = Ogre::ColourValue::White;
	    textzoneTextSize = 14;

	    textzoneBorder = Gorilla::rgb(70, 70, 70, 50);
	    textzoneBorderHighlight = Gorilla::rgb(255, 100, 100, 255);
	    textzoneBorderSelected = Gorilla::rgb(255, 200, 200, 200);
	    textzoneBorderSize = 1;

	    // Caption
	    captionBackgroundGradientType = Gorilla::Gradient_NorthSouth;
	    captionBackgroundGradientStart = transparent;
	    captionBackgroundGradientEnd = transparent;

	    captionBorder = transparent;
	    captionText = Ogre::ColourValue::White;
	    captionTextSize = 14;
	    captionBorderSize = 0;

	    // ProgressBar
	    progressbarBackgroundGradientType = Gorilla::Gradient_NorthSouth;
	    progressbarBackgroundGradientStart = Gorilla::rgb(255, 255, 255, 50);
	    progressbarBackgroundGradientEnd = Gorilla::rgb(255, 255, 255, 70);

	    progressbarLoadingBarGradientType = Gorilla::Gradient_NorthSouth;
	    progressbarLoadingBarGradientStart = Gorilla::rgb(120, 20, 120, 200);
	    progressbarLoadingBarGradientEnd = Gorilla::rgb(120, 20, 120, 150);

	    progressbarText = Ogre::ColourValue::White;
	    progressbarTextSize = 14;

	    progressbarBorder = Gorilla::rgb(70, 70, 70, 50);
	    progressbarBorderHighlight = Gorilla::rgb(255, 100, 100, 170);
	    progressbarBorderSize = 1;
	}
};

void loadDefaultPanelColors(Gui3D::PanelColors* colors) {
	*colors = _DefaultPanelColors();
}

void loadPanelColors(Gui3D::PanelColors* colors, const std::string& name, const std::string& group) {
	// TODO: load panel colors
}

}
