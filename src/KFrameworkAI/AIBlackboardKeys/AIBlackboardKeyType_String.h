#pragma once
#include "AIBlackboardKeyType_Base.h"

class BlackboardKeyType_String : public BlackboardKeyType_Base
{
public:
    BlackboardKeyType_String();

    virtual ~BlackboardKeyType_String();

    void PreInitializeKey() override;
    void DeInitializeKey() override;
};