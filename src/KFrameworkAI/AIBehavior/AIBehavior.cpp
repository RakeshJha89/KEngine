
#include "AIBehavior.h"

Behavior::Behavior()
:	m_ActionInitialize(nullptr),
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
		OnTerminate();
	}

	return GetStatus();
}

BehaviorStatus  Behavior::OnInitialize()
{
	SetStatus(BehaviorStatus_Invalid);
	return GetStatus();
}

BehaviorStatus  Behavior::OnUpdate()
{
	SetStatus(BehaviorStatus_Invalid);
	return GetStatus();
}

BehaviorStatus  Behavior::OnTerminate()
{
	SetStatus(BehaviorStatus_Invalid);
	return GetStatus();
}