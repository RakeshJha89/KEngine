#pragma once
#include "AIComposite.h"

class Parallel : public Composite
{
public:
    Parallel();

    void            SetMaxChildRun(int val) { m_maxChildToRun = val; }
private:
    void            OnInitialize() override;
    BehaviorStatus  OnUpdate() override;

    int m_maxChildToRun;
};