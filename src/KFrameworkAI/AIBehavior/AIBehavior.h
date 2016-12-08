#pragma once

#include "IBehaviorCallee.h"
#include "AIBehaviorEnums.h"
#include "AIBehaviorDelegate.h"

class BehaviorBase
{
public:

    BehaviorBase();
    virtual ~BehaviorBase() noexcept;   

    virtual BehaviorStatus  GetStatus() { return m_behaviorStatus; }

    virtual void            SetStatus(BehaviorStatus status) { m_behaviorStatus = status; }

    virtual void            SetOnInitialize(BehaviorDelegate<TFuncPtr<IBehaviorCallee, void>>* callback) { m_OnInitialize = callback; }
    virtual void            SetOnInitialize(BehaviorDelegate<TFuncPtrG<void>>* callback) { m_OnInitializeGlobal = callback; }

    virtual void            SetOnUpdate(BehaviorDelegate<TFuncPtr<IBehaviorCallee, BehaviorStatus>>* callback) { m_OnUpdate = callback; }
    virtual void            SetOnUpdate(BehaviorDelegate<TFuncPtrG<BehaviorStatus>>* callback) { m_OnUpdateGlobal = callback; }

    virtual void            SetOnTerminate(BehaviorDelegate<TFuncPtr<IBehaviorCallee, void, BehaviorStatus>>* callback) { m_OnTerminate = callback; }
    virtual void            SetOnTerminate(BehaviorDelegate<TFuncPtrG<void, BehaviorStatus>>* callback) { m_OnTerminateGlobal = callback; }

    virtual BehaviorStatus Tick(float dt = 0.0f);
    virtual void            Reset() {};
    
protected:

    virtual void            OnInitialize();
    virtual BehaviorStatus  OnUpdate();
    virtual void            OnTerminate(BehaviorStatus status);

private:


    BehaviorBase(const BehaviorBase& rhs) = delete;
    BehaviorBase& operator=(const BehaviorBase& rhs) = delete;

    void ResetData();

    BehaviorDelegate<TFuncPtr<IBehaviorCallee, void>>*                        m_OnInitialize;
    BehaviorDelegate<TFuncPtr<IBehaviorCallee, BehaviorStatus>>*              m_OnUpdate;
    BehaviorDelegate<TFuncPtr<IBehaviorCallee, void, BehaviorStatus>>*        m_OnTerminate;

    BehaviorDelegate<TFuncPtrG<void>>*                                        m_OnInitializeGlobal;
    BehaviorDelegate<TFuncPtrG<BehaviorStatus>>*                              m_OnUpdateGlobal;
    BehaviorDelegate<TFuncPtrG<void, BehaviorStatus>>*                        m_OnTerminateGlobal;

    BehaviorStatus                  m_behaviorStatus;
};



//(*m_ActionInitialize)(); //TODO: This call binding can be there for ActionBehavior;

// 
// BehaviorStatus Behavior::Initialize()
// {
// 	BehaviorStatus status = BehaviorStatus_Success;
// 	status = m_ActionInitialize(); //TODO: Move this from normal behavior to Node behavior i.e ActionsBehavior;
// 	return status;
// }


