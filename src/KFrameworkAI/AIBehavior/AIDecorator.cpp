#include "AIDecorator.h"


Decorator::Decorator()
    :   m_CanExecute(NULL),
        m_CanExecuteG(NULL)
{
    m_decoratorStatus = BHFailure;
}

BehaviorBase* Decorator::AddChild(BehaviorBase* child)
{
    if (GetChildCount() > 1)
    {
        //TODO: ASSERT(Adding more the 1 child is not allowed for a Decorator)
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