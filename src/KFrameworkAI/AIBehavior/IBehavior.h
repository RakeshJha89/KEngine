/*
	AIFramework - Behavior system.
	Created/Maintained - rakesh.jha@ubisoft.com
*/
#pragma once

#include "AICommon.h"
#include "AIBehavior/AIActionBind.h"
#include "AIBehavior/IBehaviorCallee.h"


class IBehavior
{
public:
	typedef void (IBehaviorCallee::*InitFunc)();
	typedef BehaviorStatus (IBehaviorCallee::*UpdateFunc)();
	typedef void (IBehaviorCallee::*TermFunc)(BehaviorStatus);

	virtual BehaviorStatus Tick(float dt = 0.0f) = 0;
	virtual BehaviorStatus	GetStatus() = 0;
	virtual bool			GetInitializeBind() = 0;

	virtual void			SetStatus(BehaviorStatus status) = 0;

	virtual void			SetOnInitialize(ActionBind<InitFunc>* callback) = 0;
	virtual void			SetOnUpdate(ActionBind<UpdateFunc>* callback) = 0;
	virtual void			SetOnTerminate(ActionBind<TermFunc>* callback) = 0;

protected:
	virtual void			OnInitialize() = 0;
	virtual BehaviorStatus	OnUpdate() = 0;
	virtual void			OnTerminate(BehaviorStatus status) = 0;
};
