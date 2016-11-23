#include "AIParallel.h"

Parallel::Parallel()
    : m_maxChildToRun(0)
{}

void Parallel::OnInitialize()
{
    if(m_maxChildToRun <= 0) //If Unset return after 1 failure as a sequence does.
        m_maxChildToRun = GetChildCount();
    Composite::OnInitialize();
}

BehaviorStatus Parallel::OnUpdate()
{
    int runCount = 0;
    while (true)
    {
        BehaviorStatus status = GetChild(m_currentChildIndex)->Tick();
        if (status == BHSuccess)
        {
            runCount++;
            if (runCount >= m_maxChildToRun)
                return BHSuccess;
        }
        else
        {
            if (status == BHFailure && (m_currentChildIndex + 1) > m_maxChildToRun)
            {
                m_currentChildIndex = 0;
                return status;
            }
        }

        if (++m_currentChildIndex == GetChildCount())
        {
            //Reached the last child with all returning success, Mark the Sequence as success.
            m_currentChildIndex = 0;
            return BHSuccess;
        }
    }
}