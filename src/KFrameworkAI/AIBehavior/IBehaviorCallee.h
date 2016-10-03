#pragma once
#include "AIBehavior/AIBehaviorStatus.h"

class IBehaviorCallee
{
public:
	virtual void InitializeCb() = 0;
	virtual BehaviorStatus UpdateCb() = 0;
	virtual void TerminateCb(BehaviorStatus status) = 0;
};