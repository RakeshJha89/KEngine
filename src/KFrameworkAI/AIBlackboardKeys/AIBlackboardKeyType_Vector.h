#pragma once
#include "AIBlackboardKeyType_Base.h"

class BlackboardKeyType_Vector : public BlackboardKeyType_Base
{
public:
    BlackboardKeyType_Vector();

    virtual ~BlackboardKeyType_Vector();

    void PreInitializeKey() override;
    void DeInitializeKey() override;
};