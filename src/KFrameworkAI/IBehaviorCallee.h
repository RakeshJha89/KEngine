#pragma once
#include "AIBehaviorEnums.h"

/*
Derive from IBehaviorCallee if client needs events for Initialize, Update, Terminate.
*/

class IBehaviorCallee
{
public:
    virtual void InitializeCb() = 0;
    virtual BehaviorStatus UpdateCb() = 0;
    virtual void TerminateCb(BehaviorStatus status) = 0;
};