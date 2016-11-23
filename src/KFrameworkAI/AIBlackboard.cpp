#include "AIBlackboard.h"

Blackboard::Blackboard()
{}

Blackboard::~Blackboard()
{
    for (auto& x : m_Keys)
    {
        delete x;
    }
    m_Keys.clear();
}

void Blackboard::AddKey(BlackboardKeyType_Base* key)
{
    BlackboardKeyEntry* bbKeyEntry = new BlackboardKeyEntry();
    bbKeyEntry->SetUID(GetKeyCount());
    bbKeyEntry->SetKeyData(key);
    m_Keys.push_back(bbKeyEntry);
}

BlackboardKeyType_Base* Blackboard::GetKeyAt(size_t idx) const
{
    return GetKeyEntryAt(idx)->GetKeyData(); 
}

BlackboardKeyEntry* Blackboard::GetKeyEntryAt(size_t idx) const
{
    return (m_Keys.size() > idx) ? m_Keys.at(idx) : nullptr;
}