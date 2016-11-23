#pragma once
#include "AIComposite.h"

class Decorator : public Composite
{
protected:

public:
    Decorator();
    virtual ~Decorator() {};

    BehaviorBase*   AddChild(BehaviorBase* child) override;

    void SetReturnStatusOverride(BehaviorStatus status) { m_decoratorStatus = status; }
    void SetCanExecute(ActionBind<TFuncPtr<IBehaviorCallee, bool>>* fnPtr) { m_CanExecute = fnPtr; }
    void SetCanExecute(ActionBind<TFuncPtrG<bool>>* fnPtr) { m_CanExecuteG = fnPtr; }


private:
    BehaviorStatus OnUpdate() override;
    ActionBind<TFuncPtr<IBehaviorCallee, bool>>* m_CanExecute;
    ActionBind<TFuncPtrG<bool>>* m_CanExecuteG;

    BehaviorStatus m_decoratorStatus;
};
