#pragma once
#include "AIComposite.h"

class ActionTask : public Composite
{
protected:

public:
    ActionTask();
    virtual ~ActionTask() {};

    BehaviorBase*   AddChild(BehaviorBase* child) override;
    
private:
    void OnInitialize() override;
    BehaviorStatus OnUpdate() override;
};

