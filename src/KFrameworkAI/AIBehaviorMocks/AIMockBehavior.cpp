#include "AIMockBehavior.h"

MockSelector::MockSelector(int size)
{
    for (int i = 0; i < size; ++i)
    {
        AddChild(new MockBehavior("MockSelector"));
    }
}

MockSequence::MockSequence(int size)
{
    for (int i = 0; i < size; ++i)
    {
        AddChild(new MockBehavior("MockSequence"));
    }
}