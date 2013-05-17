/*
 * ZzOGRE.h
 *
 *  Created on: 2013/4/1
 *      Author: SUCHEN
 */

#ifndef ZZOGRE_H_
#define ZZOGRE_H_

#define ZZOGRE_MAJOR_VERSION		0
#define ZZOGRE_MINOR_VERSION		1

#define _ZZOGRE_STR(s) #s
#define ZZOGRE_STR(s) _ZZOGRE_STR(s)
#define ZZOGRE_VERSION				ZZOGRE_STR(ZZOGRE_MAJOR_VERSION) "." ZZOGRE_STR(ZZOGRE_MINOR_VERSION)

#include "zzlab/ZzLab.h"

#include <vector>

#include <OgreRoot.h>
#include <OgreRenderWindow.h>
#include <OgreArchiveManager.h>
#include <OgreConfigFile.h>
#include <OgreCompositorManager.h>
#include <OgreControllerManager.h>
#include <OgreGpuProgramManager.h>
#include <OgreHighLevelGpuProgramManager.h>
#include <OgreMeshManager.h>
#include <OgreOverlayManager.h>
#include <OgreParticleSystemManager.h>
#include <OgreProfiler.h>
#include <OgreSkeletonManager.h>
#include <OgreHardwarePixelBuffer.h>
#include <OgreHardwareBufferManager.h>
#include <OgreRenderWindow.h>
#include <OgreRectangle2D.h>
#include <OgreAxisAlignedBox.h>
#include <OgreMovableObject.h>

#include <OISMouse.h>
#include <OISKeyboard.h>

#include "OISRenderWindow.h"
#include "gui3d/Gui3D.h"
#include "gui3d/Gui3DPanel.h"
#include "gui3d/Gui3DScreenPanel.h"
#include "gui3d/Gui3DPanelColors.h"
#include "Euler.h"

#include <boost/filesystem.hpp>

#define ZzOgreAssert( a, b ) if( !(a) ) OGRE_EXCEPT( Ogre::Exception::ERR_RT_ASSERTION_FAILED, (b), __FUNCTION__ )

namespace zzogre {

	extern Ogre::Root* _Root;
	extern Ogre::RenderSystem* _RenderSystem;
	extern Ogre::ResourceGroupManager* _ResourceGroupManager;
	extern Ogre::ArchiveManager* _ArchiveManager;
	extern Ogre::CompositorManager* _CompositorManager;
	extern Ogre::ControllerManager* _ControllerManager;
	extern Ogre::GpuProgramManager* _GpuProgramManager;
	extern Ogre::HardwareBufferManager* _HardwareBufferManager;
	extern Ogre::HighLevelGpuProgramManager* _HighLevelGpuProgramManager;
	extern Ogre::LogManager* _LogManager;
	extern Ogre::MaterialManager* _MaterialManager;
	extern Ogre::MeshManager* _MeshManager;
	extern Ogre::OverlayManager* _OverlayManager;
	extern Ogre::ParticleSystemManager* _ParticleSystemManager;
	extern Ogre::Profiler* _Profiler;
	extern Ogre::ResourceBackgroundQueue* _ResourceBackgroundQueue;
	extern Ogre::SceneManagerEnumerator* _SceneManagerEnumerator;
	extern Ogre::ShadowTextureManager* _ShadowTextureManager;
	extern Ogre::SkeletonManager* _SkeletonManager;
	extern Ogre::TextureManager* _TextureManager;
	extern Ogre::SceneManager* _SceneManager;

	extern OISRenderWindowPtr _Window;
	extern std::vector<OISRenderWindowPtr> _Windows;

	extern Gui3D::Gui3D* _Gui3D;

	extern Ogre::AxisAlignedBox EmptyAABB;
	extern Ogre::Rect EmptyRect;

	ZZLAB_TYPEDEF_SHARED_PTR1(Ogre::Rectangle2D, Rectangle2D);
	ZZLAB_TYPEDEF_SHARED_PTR1(Gui3D::Panel, Panel);
	ZZLAB_TYPEDEF_SHARED_PTR1(Gui3D::ScreenPanel, ScreenPanel);

	extern void cacheSingletons();
	extern void addResourceGroups(boost::filesystem::path p);
	extern void loadAllBehaviors(boost::filesystem::path p);
	extern void setRenderWindowActive(Ogre::RenderWindow* rw);

	inline void beginRenderWindowResources(Ogre::RenderWindow* rw) {
		_RenderSystem->setConfigOption("Resource Creation Policy",
				"Create on active device");
		setRenderWindowActive(rw);
	}

	inline void endRenderWindowResources() {
		_RenderSystem->setConfigOption("Resource Creation Policy", "Create on all devices");
	}

	struct RenderWindowResourcesClosure {
		RenderWindowResourcesClosure(Ogre::MovableObject* movableObject);

		RenderWindowResourcesClosure(const std::string& name) : inClosure(true) {
			beginRenderWindowResources(dynamic_cast<Ogre::RenderWindow*>(_Root->getRenderTarget(name)));
		}

		RenderWindowResourcesClosure(Ogre::RenderWindow* rw) : inClosure(true)  {
			beginRenderWindowResources(rw);
		}

		~RenderWindowResourcesClosure() {
			if(inClosure)
				endRenderWindowResources();
		}

		bool inClosure;
	};
	ZZLAB_TYPEDEF_SHARED_PTR(RenderWindowResourcesClosure);

	extern Ogre::String toString(const Euler& val);
	extern Euler parseEuler(const Ogre::String& val, const Euler& defaultValue = Euler::ZERO);

	extern Ogre::String toString(const Ogre::AxisAlignedBox& val);
	extern Ogre::AxisAlignedBox parseAxisAlignedBox(const Ogre::String& val, const Ogre::AxisAlignedBox& defaultValue = EmptyAABB);

	extern Ogre::String toString(const Ogre::Rect& val);
	extern Ogre::Rect parseRect(const Ogre::String& val, const Ogre::Rect& defaultValue = EmptyRect);

	extern Ogre::String flagsToString(const uint32_t& val);
	extern uint32_t parseFlags(const Ogre::String& val, const uint32_t& defaultValue = 0xFFFFFFFF);

	extern Ogre::PixelFormat parsePixelFormat(const Ogre::String& val, const Ogre::PixelFormat& defaultValue = Ogre::PF_R8G8B8);

	extern void loadScene(const std::string& name, const std::string& group, Ogre::SceneManager*& ret);
	extern void writeScene(Ogre::SceneManager* scene, const std::string& filename);

	extern Ogre::RenderTarget* getRenderTarget(const Ogre::String& name);

	extern void loadDefaultPanelColors(Gui3D::PanelColors* colors);
	extern void loadPanelColors(Gui3D::PanelColors* colors, const std::string& name, const std::string& group);
}

#endif /* ZZOGRE_H_ */
