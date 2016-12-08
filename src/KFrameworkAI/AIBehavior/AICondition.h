#pragma once
#include "AIBehavior.h"

class Condition : public BehaviorBase
{
protected:

public:
    Condition();
    virtual ~Condition() {};

    void SetCanExecute(BehaviorDelegate<TFuncPtr<IBehaviorCallee, bool>>* fnPtr) { m_CanExecute = fnPtr; }
    void SetCanExecute(BehaviorDelegate<TFuncPtrG<bool>>* fnPtr) { m_CanExecuteG = fnPtr; }

private:
    BehaviorStatus OnUpdate() override;

    BehaviorDelegate<TFuncPtr<IBehaviorCallee, bool>>* m_CanExecute;
    BehaviorDelegate<TFuncPtrG<bool>>* m_CanExecuteG;
};