#pragma once
#include <string>
#include <vector>
#include "AIBehaviorEnums.h"

#include "AIBlackboardKeys/AIBlackboardKeyType_Base.h"


class BlackboardKeyEntry
{
public:

    BlackboardKeyEntry()
    {
        m_KeyName = "Default";
        m_KeyData = nullptr;
    }

    ~BlackboardKeyEntry()
    {
        delete m_KeyData;
    }

    int32_t                 GetUID() const { return m_UniqueId; }
    void                    SetUID(int32_t val) { m_UniqueId = val; }

    std::string             GetKeyName() const { return m_KeyName; }
    void                    SetKeyName(std::string val) { m_KeyName = val; }

    BlackboardKeyType_Base* GetKeyData() const { return m_KeyData; }
    void                    SetKeyData(BlackboardKeyType_Base* val) { m_KeyData = val; }

private:
    int32_t m_UniqueId; //Maybe later have this generated using a UID generation function based on KeyEntryName.
    std::string m_KeyName;
    BlackboardKeyType_Base* m_KeyData;

};

class Blackboard
{
public: 
    Blackboard();
    virtual ~Blackboard();

    void                                        AddKey(BlackboardKeyType_Base* key);
    size_t                                      GetKeyCount() const { return m_Keys.size(); }
    BlackboardKeyType_Base*                     GetKeyAt(size_t idx) const;
    BlackboardKeyEntry*                         GetKeyEntryAt(size_t idx) const;

private:
    std::vector<BlackboardKeyEntry*> m_Keys;
};