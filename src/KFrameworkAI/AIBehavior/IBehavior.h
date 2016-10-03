/*
	AIFramework - Behavior system.
	Created/Maintained - rakesh.jha@ubisoft.com
*/
#pragma once

#include "AICommon.h"
#include "AIBehavior/AIBehaviorStatus.h"
#include "AIBehavior/AIActionBind.h"

class IBehavior
{
public:
	virtual BehaviorStatus Tick(float dt = 0.0f) = 0;

	virtual BehaviorStatus	GetStatus() = 0;
	virtual bool			GetInitializeBind() = 0;

	virtual void			SetStatus(BehaviorStatus status) = 0;

	virtual void			SetOnInitialize(ActionBind<BehaviorStatus>* actionBind) = 0;
	virtual void			SetOnUpdate(ActionBind<BehaviorStatus>* actionBind) = 0;
	virtual void			SetOnTerminate(ActionBind<BehaviorStatus>* actionBind) = 0;

	virtual BehaviorStatus			OnInitialize() = 0;
	virtual BehaviorStatus			OnUpdate() = 0;
	virtual BehaviorStatus			OnTerminate() = 0;
};
