#include "AIBlackboardKeyType_Integer.h"

BlackboardKeyType_Integer::BlackboardKeyType_Integer()
{
    PreInitializeKey();
}

BlackboardKeyType_Integer::~BlackboardKeyType_Integer()
{
    DeInitializeKey();
}

void BlackboardKeyType_Integer::PreInitializeKey()
{
    //Allocate memory based on the type of m_KeyValue;
    printf("Allocating for Int\n");
    m_KeySize = sizeof(int);
    m_KeyValue = std::malloc(m_KeySize);
    std::memset(m_KeyValue, 0x0, m_KeySize);
}

void BlackboardKeyType_Integer::DeInitializeKey()
{
    //UnAllocate memory;
    std::free(m_KeyValue);
    m_KeyValue = nullptr;
}