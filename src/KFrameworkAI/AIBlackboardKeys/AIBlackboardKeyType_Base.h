#pragma once
#include <string>

class BlackboardKeyType_Base
{
public:
    BlackboardKeyType_Base();
    virtual ~BlackboardKeyType_Base();
    
    template <typename T>
    T               GetKeyValue() const { return *((T*)m_KeyValue); }
    template <typename T>
    void            SetKeyValue(T val);


protected:
    virtual void PreInitializeKey() = 0;
    virtual void DeInitializeKey() = 0;

    void*       m_KeyValue;
    size_t      m_KeySize;
};

template <typename T>
void   BlackboardKeyType_Base::SetKeyValue(T val)
{
    std::memcpy(m_KeyValue, &val, m_KeySize);
}

