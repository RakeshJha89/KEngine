#pragma once

#include "IBehaviorCallee.h"
#include "AIBehaviorEnums.h"
#include "AIBehavior/AIActionBind.h"

class BehaviorBase
{
public:

    BehaviorBase();
    virtual ~BehaviorBase() noexcept;   

    virtual BehaviorStatus  GetStatus() { return m_behaviorStatus; }

    virtual void            SetStatus(BehaviorStatus status) { m_behaviorStatus = status; }

    virtual void            SetOnInitialize(ActionBind<TFuncPtr<IBehaviorCallee, void>>* callback) { m_OnInitialize = callback; }
    virtual void            SetOnInitialize(ActionBind<TFuncPtrG<void>>* callback) { m_OnInitializeGlobal = callback; }

    virtual void            SetOnUpdate(ActionBind<TFuncPtr<IBehaviorCallee, BehaviorStatus>>* callback) { m_OnUpdate = callback; }
    virtual void            SetOnUpdate(ActionBind<TFuncPtrG<BehaviorStatus>>* callback) { m_OnUpdateGlobal = callback; }

    virtual void            SetOnTerminate(ActionBind<TFuncPtr<IBehaviorCallee, void, BehaviorStatus>>* callback) { m_OnTerminate = callback; }
    virtual void            SetOnTerminate(ActionBind<TFuncPtrG<void, BehaviorStatus>>* callback) { m_OnTerminateGlobal = callback; }

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

    ActionBind<TFuncPtr<IBehaviorCallee, void>>*                        m_OnInitialize;
    ActionBind<TFuncPtr<IBehaviorCallee, BehaviorStatus>>*              m_OnUpdate;
    ActionBind<TFuncPtr<IBehaviorCallee, void, BehaviorStatus>>*        m_OnTerminate;

    ActionBind<TFuncPtrG<void>>*                                        m_OnInitializeGlobal;
    ActionBind<TFuncPtrG<BehaviorStatus>>*                              m_OnUpdateGlobal;
    ActionBind<TFuncPtrG<void, BehaviorStatus>>*                        m_OnTerminateGlobal;

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


