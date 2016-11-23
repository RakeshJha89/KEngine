#pragma once
#include "AIBlackboardKeyType_Base.h"

class BlackboardKeyType_Integer : public BlackboardKeyType_Base
{
public:
    BlackboardKeyType_Integer();

    virtual ~BlackboardKeyType_Integer();

    void PreInitializeKey() override;
    void DeInitializeKey() override;
};