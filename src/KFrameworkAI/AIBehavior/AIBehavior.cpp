
#include "AIBehavior.h"

BehaviorBase::BehaviorBase()
:	m_OnInitialize(nullptr),
    m_OnUpdate(nullptr),
    m_OnTerminate(nullptr),
    m_OnInitializeGlobal(nullptr),
    m_OnUpdateGlobal(nullptr),
    m_OnTerminateGlobal(nullptr),
    m_behaviorStatus(BHInvalid)
{

}


BehaviorBase::~BehaviorBase() noexcept
{
    ResetData();
}


void BehaviorBase::ResetData()
{
    m_OnInitialize = nullptr;
    m_OnUpdate = nullptr;
    m_OnTerminate = nullptr;
    m_OnInitializeGlobal = nullptr;
    m_OnUpdateGlobal = nullptr;
    m_OnTerminateGlobal = nullptr;
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
    if(m_OnInitialize != nullptr)
        (*m_OnInitialize)();
    if(m_OnInitializeGlobal != nullptr)
        (*m_OnInitializeGlobal)();

    BehaviorStatus st = BHRunning;
    SetStatus(st);
}

BehaviorStatus  BehaviorBase::OnUpdate()
{
    BehaviorStatus st = GetStatus();
    if(m_OnUpdate != nullptr)
         st = (*m_OnUpdate)();
    if(m_OnUpdateGlobal != nullptr)
        st = (*m_OnUpdateGlobal)();

    return st;
}

void  BehaviorBase::OnTerminate(BehaviorStatus st)
{
    if(m_OnTerminate != nullptr)
        (*m_OnTerminate)(st);
    if(m_OnTerminateGlobal != nullptr)
        (*m_OnTerminateGlobal)(st);

    SetStatus(st);
}