#pragma once
#include "AIBehavior/AIBehavior.h"

class MockBehavior : public Behavior
{
public:
	MockBehavior();
	virtual ~MockBehavior();
	virtual BehaviorStatus Tick(float dt) override;

	virtual BehaviorStatus OnInitialize() override;
	virtual BehaviorStatus OnUpdate() override;
	virtual BehaviorStatus OnTerminate() override;
};

