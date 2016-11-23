#pragma once
#include "AIBlackboardKeyType_Base.h"

class BlackboardKeyType_Float : public BlackboardKeyType_Base
{
public:
    BlackboardKeyType_Float();

    virtual ~BlackboardKeyType_Float();

    void PreInitializeKey() override;
    void DeInitializeKey() override;
};