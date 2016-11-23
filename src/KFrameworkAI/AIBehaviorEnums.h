#pragma once

enum BehaviorStatus
{
    BHInvalid = 0,
    BHRunning,
    BHSuccess,
    BHFailure
};

enum BlackboardKeyTypes
{
    BaseType = 0,
    BooleanType,
    FloatType,
    IntegerType,
    StringType,
    ObjectType,
    VectorType
};

