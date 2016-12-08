#pragma once
#include <string>
#include "AIBlackboardKeyType_Base.h"

class BlackboardKeyType_Object : public BlackboardKeyType_Base
{
public:
    BlackboardKeyType_Object();

    virtual ~BlackboardKeyType_Object();

    void PreInitializeKey() override;
    void DeInitializeKey() override;
};