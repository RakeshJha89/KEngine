#include "AIBlackboardKeyType_String.h"

BlackboardKeyType_String::BlackboardKeyType_String()
{
    PreInitializeKey();
}

BlackboardKeyType_String::~BlackboardKeyType_String()
{
    DeInitializeKey();
}

void BlackboardKeyType_String::PreInitializeKey()
{
    //Allocate memory based on the type of m_KeyValue;
    printf("Allocating for Boolean\n");
    m_KeySize = sizeof(char) * 128; //Allocating some char space.
    m_KeyValue = std::malloc(m_KeySize);
    std::memset(m_KeyValue, 0x0, m_KeySize);
}

void BlackboardKeyType_String::DeInitializeKey()
{
    //UnAllocate memory;
    std::free(m_KeyValue);
    m_KeyValue = nullptr;
}