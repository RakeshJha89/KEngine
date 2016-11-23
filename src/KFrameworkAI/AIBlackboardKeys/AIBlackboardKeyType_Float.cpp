#include "AIBlackboardKeyType_Float.h"

BlackboardKeyType_Float::BlackboardKeyType_Float()
{
    PreInitializeKey();
}

BlackboardKeyType_Float::~BlackboardKeyType_Float()
{
    DeInitializeKey();
}

void BlackboardKeyType_Float::PreInitializeKey()
{
    //Allocate memory based on the type of m_KeyValue;
    printf("Allocating for Float\n");
    m_KeySize = sizeof(float);
    m_KeyValue = std::malloc(m_KeySize);
    std::memset(m_KeyValue, 0x0, m_KeySize);
}

void BlackboardKeyType_Float::DeInitializeKey()
{
    //UnAllocate memory;
    std::free(m_KeyValue);
    m_KeyValue = nullptr;
}