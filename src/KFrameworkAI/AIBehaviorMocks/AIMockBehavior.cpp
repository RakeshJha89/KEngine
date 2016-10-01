#include "AIMockBehavior.h"

MockBehavior::MockBehavior()
{
	//Do some initialization work here.
}

MockBehavior::~MockBehavior()
{
	//DO cleanup work here.
}

BehaviorStatus MockBehavior::Tick(float dt)
{
	return Behavior::Tick(dt);
}

BehaviorStatus  MockBehavior::OnInitialize()
{
	SetStatus(BehaviorStatus_Running);
	return GetStatus();
}

BehaviorStatus  MockBehavior::OnUpdate()
{
	SetStatus(BehaviorStatus_Success);
	return GetStatus();
}

BehaviorStatus  MockBehavior::OnTerminate()
{
	SetStatus(BehaviorStatus_Invalid);
	return GetStatus();
}