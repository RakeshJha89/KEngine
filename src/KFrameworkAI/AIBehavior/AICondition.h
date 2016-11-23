#pragma once
#include "AIBehavior.h"

class Condition : public BehaviorBase
{
protected:

public:
    Condition();
    virtual ~Condition() {};

    void SetCanExecute(ActionBind<TFuncPtr<IBehaviorCallee, bool>>* fnPtr) { m_CanExecute = fnPtr; }
    void SetCanExecute(ActionBind<TFuncPtrG<bool>>* fnPtr) { m_CanExecuteG = fnPtr; }

private:
    BehaviorStatus OnUpdate() override;

    ActionBind<TFuncPtr<IBehaviorCallee, bool>>* m_CanExecute;
    ActionBind<TFuncPtrG<bool>>* m_CanExecuteG;
};