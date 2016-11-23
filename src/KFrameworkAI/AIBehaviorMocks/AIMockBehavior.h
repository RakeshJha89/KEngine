#pragma once
#include "AIBehavior/AIBehavior.h"
#include "AIBehavior/AISelector.h"
#include "AIBehavior/AISequence.h"

class MockBehavior : public BehaviorBase
{
public:
    MockBehavior() {};
    MockBehavior(std::string parent) { m_parentName = parent; }
    virtual ~MockBehavior() {};
private:
    std::string m_parentName;
};

class MockSelector : public Selector
{
public:
    MockSelector(int size) ;
    virtual ~MockSelector() {};
};


class MockSequence : public Sequence
{
public:
    MockSequence(int size);
    virtual ~MockSequence() {};
};
