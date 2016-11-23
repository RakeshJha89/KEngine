#include "AIBlackboardKeyType_Boolean.h"

BlackboardKeyType_Boolean::BlackboardKeyType_Boolean()
{
    PreInitializeKey();
}

BlackboardKeyType_Boolean::~BlackboardKeyType_Boolean()
{
    DeInitializeKey();
}

void BlackboardKeyType_Boolean::PreInitializeKey()
{
    //Allocate memory based on the type of m_KeyValue;
    printf("Allocating for Boolean\n");
    m_KeySize = sizeof(bool);
    m_KeyValue = std::malloc(m_KeySize);
    std::memset(m_KeyValue, 0x0, m_KeySize);
}

void BlackboardKeyType_Boolean::DeInitializeKey()
{
    //UnAllocate memory;
    std::free(m_KeyValue);
    m_KeyValue = nullptr;
}