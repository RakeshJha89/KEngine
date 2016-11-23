
#include "AIBehavior.h"

BehaviorBase::BehaviorBase()
:	m_OnInitialize(NULL),
    m_OnUpdate(NULL),
    m_OnTerminate(NULL),
    m_OnInitializeGlobal(NULL),
    m_OnUpdateGlobal(NULL),
    m_OnTerminateGlobal(NULL),
    m_behaviorStatus(BHInvalid)
{

}


BehaviorBase::~BehaviorBase() noexcept
{
    ResetData();
}


void BehaviorBase::ResetData()
{
    m_OnInitialize = NULL;
    m_OnUpdate = NULL;
    m_OnTerminate = NULL;
    m_OnInitializeGlobal = NULL;
    m_OnUpdateGlobal = NULL;
    m_OnTerminateGlobal = NULL;
    m_behaviorStatus = BHInvalid;
}

BehaviorStatus BehaviorBase::Tick(float dt)
{
    if (GetStatus() == BHInvalid)
    {
        OnInitialize();
    }

    SetStatus(OnUpdate());

    if (GetStatus() != BHRunning)
    {
        OnTerminate(GetStatus());
    }

    return GetStatus();
}

void  BehaviorBase::OnInitialize()
{
    if(m_OnInitialize != NULL)
        (*m_OnInitialize)();
    if(m_OnInitializeGlobal != NULL)
        (*m_OnInitializeGlobal)();

    BehaviorStatus st = BHRunning;
    SetStatus(st);
}

BehaviorStatus  BehaviorBase::OnUpdate()
{
    BehaviorStatus st = GetStatus();
    if(m_OnUpdate != NULL)
         st = (*m_OnUpdate)();
    if(m_OnUpdateGlobal != NULL)
        st = (*m_OnUpdateGlobal)();

    return st;
}

void  BehaviorBase::OnTerminate(BehaviorStatus st)
{
    if(m_OnTerminate != NULL)
        (*m_OnTerminate)(st);
    if(m_OnTerminateGlobal != NULL)
        (*m_OnTerminateGlobal)(st);

    SetStatus(st);
}