#include "AIBehavior/AIComposite.h"

Composite::Composite()
    :   m_currentChildIndex(0),
        m_childBehaviors()
{
}

Composite::~Composite()
{
    for (auto& x : m_childBehaviors)
    {
        delete x;
    }
    m_childBehaviors.clear();
}


BehaviorBase* Composite::AddChild(BehaviorBase* child)
{
    m_childBehaviors.push_back(child);
    return m_childBehaviors.back();
}

void Composite::RemoveChild(BehaviorBase* child)
{
    auto it = std::find(m_childBehaviors.begin(), m_childBehaviors.end(), child);
    if (it != m_childBehaviors.end())
        m_childBehaviors.erase(it);
}

BehaviorStatus  Composite::OnUpdate()
{
    //Default return Running.
    return BHRunning;
}

void Composite::Reset()
{
    m_currentChildIndex = 0;
    SetStatus(BHInvalid);
    for (auto &i : m_childBehaviors)
    {
        i->SetStatus(BHInvalid);
    }
}


