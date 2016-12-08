#include "AIDecorator.h"


Decorator::Decorator()
    :   m_CanExecute(nullptr),
        m_CanExecuteG(nullptr)
{
    m_decoratorStatus = BHFailure;
}

BehaviorBase* Decorator::AddChild(BehaviorBase* child)
{
    if (GetChildCount() > 1)
    {
        return GetChild(0);
    }
    return Composite::AddChild(child);
}

BehaviorStatus Decorator::OnUpdate()
{
    if ((m_CanExecute != nullptr && ((*m_CanExecute)())) || (m_CanExecuteG != nullptr && ((*m_CanExecuteG)())))
    {
        return GetChild(0)->Tick();
    }
    return m_decoratorStatus;
}