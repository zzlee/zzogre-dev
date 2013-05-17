/*
 * FrameStatsView.h
 *
 *  Created on: 2013/4/10
 *      Author: SUCHEN
 */

#ifndef FRAMESTATSVIEW_H_
#define FRAMESTATSVIEW_H_

#include <zzogre/Behavior.h>
#include <zzogre/ZzOGRE.h>

#include <gui3d/Gorilla.h>
#include <gui3d/Gui3DCaption.h>

#include <OgreCamera.h>

namespace zzogre {

class FrameStatsView: public Behavior {
ZZOGRE_COMPONENT_TYPE(FrameStatsView);

public:
	FrameStatsView();
	virtual ~FrameStatsView();

protected:
	virtual void onEnable();
	virtual void onDisable();

	virtual void onFrameStarted();

	Ogre::RenderTarget* mRenderTarget;

	zzogre::ScreenPanelPtr mPanel;
	Gui3D::Caption* mCurrFPS;
	Gui3D::Caption* mAvgFPS;
	Gui3D::Caption* mWorstFPS;
	Gui3D::Caption* mBestFPS;
	Gui3D::Caption* mTriCount;
	Gui3D::Caption* mBatchCount;
};

} /* namespace zzogre */
#endif /* FRAMESTATSVIEW_H_ */
