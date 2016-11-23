#pragma once
#include "AISelector.h"

class PrioritySelector : public Selector
{
public:
    PrioritySelector();

private:

    BehaviorStatus  OnUpdate() override;

    int m_lastChildIndex;
};