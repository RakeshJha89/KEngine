#pragma once

#include <vector>
#include "IBehaviorCallee.h"
#include "AIBehavior/AIBehavior.h"


class Composite : public BehaviorBase
{
public:
    Composite();
    virtual ~Composite();


    virtual BehaviorBase*   AddChild(BehaviorBase* child);
    void                    RemoveChild(BehaviorBase* child);
    int	                    GetChildCount() { return m_childBehaviors.size(); }
    BehaviorBase*           GetChild(int idx) { return m_childBehaviors.at(idx); }
    void Reset() override;

protected:
    virtual BehaviorStatus  OnUpdate() override;

    int m_currentChildIndex;
    std::vector<BehaviorBase*> m_childBehaviors;
};

