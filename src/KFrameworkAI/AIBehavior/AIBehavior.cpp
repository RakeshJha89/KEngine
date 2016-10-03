
#include "AIBehavior.h"

Behavior::Behavior()
:	m_OnInitialize(NULL),
	m_OnUpdate(NULL),
	m_OnTerminate(NULL),
	m_behaviorStatus(BehaviorStatus_Invalid)
{

}

Behavior::~Behavior()
{
	SetStatus(BehaviorStatus_Invalid);
}

BehaviorStatus Behavior::Tick(float dt)
{
	if (GetStatus() == BehaviorStatus_Invalid && GetInitializeBind())
	{
		OnInitialize();
	}

	OnUpdate();

	if (GetStatus() != BehaviorStatus_Running)
	{
		OnTerminate(GetStatus());
	}

	return GetStatus();
}

void  Behavior::OnInitialize()
{
	SetStatus(BehaviorStatus_Invalid);
}

BehaviorStatus  Behavior::OnUpdate()
{
	SetStatus(BehaviorStatus_Invalid);
	return GetStatus();
}

void  Behavior::OnTerminate(BehaviorStatus)
{
	SetStatus(BehaviorStatus_Invalid);
}