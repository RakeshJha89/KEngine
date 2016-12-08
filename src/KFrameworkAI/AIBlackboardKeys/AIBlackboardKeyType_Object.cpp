#include "AIBlackboardKeyType_Object.h"

BlackboardKeyType_Object::BlackboardKeyType_Object()
{
    PreInitializeKey();
}

BlackboardKeyType_Object::~BlackboardKeyType_Object()
{
    DeInitializeKey();
}

void BlackboardKeyType_Object::PreInitializeKey()
{
    //Allocate memory based on the type of m_KeyValue;
    printf("Allocating for Object\n");
    m_KeySize = sizeof(Object);
    m_KeyValue = std::malloc(m_KeySize);
    std::memset(m_KeyValue, 0x0, m_KeySize);
}

void BlackboardKeyType_Object::DeInitializeKey()
{
    //UnAllocate memory;
    std::free(m_KeyValue);
    m_KeyValue = nullptr;
}