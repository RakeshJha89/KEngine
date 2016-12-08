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
    void SetCanExecute(BehaviorDelegate<TFuncPtr<IBehaviorCallee, bool>>* fnPtr) { m_CanExecute = fnPtr; }
    void SetCanExecute(BehaviorDelegate<TFuncPtrG<bool>>* fnPtr) { m_CanExecuteG = fnPtr; }


private:
    BehaviorStatus OnUpdate() override;
    BehaviorDelegate<TFuncPtr<IBehaviorCallee, bool>>* m_CanExecute;
    BehaviorDelegate<TFuncPtrG<bool>>* m_CanExecuteG;

    BehaviorStatus m_decoratorStatus;
};
