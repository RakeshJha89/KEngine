#pragma once
#include "AIBlackboardKeyType_Base.h"

class BlackboardKeyType_Boolean : public BlackboardKeyType_Base
{
public:
    BlackboardKeyType_Boolean();

    virtual ~BlackboardKeyType_Boolean();

    void PreInitializeKey() override;
    void DeInitializeKey() override;
};