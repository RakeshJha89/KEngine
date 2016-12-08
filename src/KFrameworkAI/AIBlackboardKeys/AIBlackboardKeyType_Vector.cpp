#include "AIBlackboardKeyType_Vector.h"

BlackboardKeyType_Vector::BlackboardKeyType_Vector()
{
    PreInitializeKey();
}

BlackboardKeyType_Vector::~BlackboardKeyType_Vector()
{
    DeInitializeKey();
}

void BlackboardKeyType_Vector::PreInitializeKey()
{
    //Allocate memory based on the type of m_KeyValue;
    printf("Allocating for Vector\n");
    m_KeySize = sizeof(float) * 3; //Allocating 3 float. Can be changed to a SIMD using instruction set __128_float
    m_KeyValue = std::malloc(m_KeySize);
    std::memset(m_KeyValue, 0x0, m_KeySize);
}

void BlackboardKeyType_Vector::DeInitializeKey()
{
    //UnAllocate memory;
    std::free(m_KeyValue);
    m_KeyValue = nullptr;
}