#include "AIBehaviorTree.h"

BehaviorTree::BehaviorTree()
    :   m_RootNode(nullptr), 
        m_TreeName("Default")
{
}

BehaviorTree::BehaviorTree(std::string treeName)
    :   m_RootNode(nullptr),
        m_TreeName(treeName)
{
}

BehaviorTree::~BehaviorTree()
{
    delete m_RootNode;
    m_RootNode = nullptr;
}

void BehaviorTree::SetRoot(Composite* composite)
{
    if (m_RootNode)
        delete m_RootNode;
    m_RootNode = composite;
}

void BehaviorTree::TickTree()
{
    if (m_RootNode)
        m_RootNode->Tick(0.0f);
}