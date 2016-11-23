#include "AICondition.h"


Condition::Condition()
    :   m_CanExecute(NULL),
        m_CanExecuteG(NULL)
{

}

BehaviorStatus Condition::OnUpdate()
{
    if ((m_CanExecute != nullptr && ((*m_CanExecute)())) || (m_CanExecuteG != nullptr && ((*m_CanExecuteG)())))
    {
        return BHSuccess;
    }
    return BHFailure;
}