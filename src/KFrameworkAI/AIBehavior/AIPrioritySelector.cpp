#include "AIPrioritySelector.h"

PrioritySelector::PrioritySelector()
    : m_lastChildIndex(0)
{}


BehaviorStatus  PrioritySelector::OnUpdate()
{
    m_currentChildIndex = 0;
    while(true)
    {
        if (GetChildCount() <= 0)
            return GetStatus();
        BehaviorStatus status = GetChild(m_currentChildIndex)->Tick();
        if (status != BHFailure)
        {
            for (int i = m_currentChildIndex + 1; i <= m_lastChildIndex; i++)
            {
                GetChild(i)->Reset();
            }
            m_lastChildIndex = m_currentChildIndex;
            return status;
        }
        if (++m_currentChildIndex == GetChildCount())
        {
            //Reached the last child without any returning success, Mark the PrioritySelector as failure.
            return BHFailure;
        }
    }
}
