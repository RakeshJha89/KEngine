#include "AISelector.h"


BehaviorStatus Selector::OnUpdate()
{
    while (true)
    {
        if (GetChildCount() <= 0)
            return GetStatus();
        BehaviorStatus status = GetChild(m_currentChildIndex)->Tick();
        if (status != BHFailure)
        {
            if (status == BHSuccess)
            {
                m_currentChildIndex = 0;
            }
            return status;
        }
        if (++m_currentChildIndex == GetChildCount())
        {
            //Reached the last child without any returning success, Mark the Selector as failure.
            m_currentChildIndex = 0;
            return BHFailure;
        }
    }
}