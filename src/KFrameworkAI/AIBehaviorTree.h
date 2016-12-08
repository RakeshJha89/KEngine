#pragma once
#include <string>
#include "AIBehavior/AIComposite.h"

class BehaviorTree
{
public:
    explicit BehaviorTree(std::string treeName = "Default");
    virtual ~BehaviorTree();

    void SetRoot(Composite* composite);
    void TickTree();

private:
    BehaviorTree();

    Composite* m_RootNode;
    std::string m_TreeName;
};