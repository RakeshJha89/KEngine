#include "AISequence.h"


BehaviorStatus Sequence::OnUpdate()
{
    while (true)
    {
        if (GetChildCount() <= 0)
            return GetStatus();
        BehaviorStatus status = GetChild(m_currentChildIndex)->Tick();
        if (status != BHSuccess)
        {
            if (status == BHFailure)
            {
                m_currentChildIndex = 0;
            }
            return status;
        }
        if (++m_currentChildIndex == GetChildCount())
        {
            //Reached the last child with all returning success, Mark the Sequence as success.
            m_currentChildIndex = 0;
            return BHSuccess;
        }
    }
}