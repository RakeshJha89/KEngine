#pragma once
#include "string"
#include "gtest/gtest.h"
#include "AICommon.h"
#include "AIBehaviorMocks/AIMockBehavior.h"

/*Examples*/

class TestBehaviorCallee : public IBehaviorCallee
{
public:
	void InitializeCb() override
	{

	}

	BehaviorStatus UpdateCb() override
	{
		return BehaviorStatus_Success;
	}

	void TerminateCb(BehaviorStatus status)
	{
		printf("Terminated with status code %d\n", status);
	}
};

struct ActionBindTest
{
	BehaviorStatus PrintPassedParam(std::string strg)
	{
		std::string passedStr = "Hello World";
		EXPECT_EQ(passedStr, strg);

		return BehaviorStatus_Success;
	}

	void PrintHelloWorld()
	{
		char* strg = "Hello World";
		EXPECT_STRCASEEQ(strg, "Hello World");
	}
};

ActionBindTest bindTest;



TEST(AIAction, Test_ActionBind)
{
 	auto ab = ACTIONBIND(&ActionBindTest::PrintHelloWorld, &bindTest);
 	ab();	//Execute.
}

TEST(AIAction, Test_ActionBind_Pass_Param)
{
 	auto ab = ACTIONBIND(&ActionBindTest::PrintPassedParam, &bindTest);
 	ab("Hello World");
}

TEST(AIBehavior, Test_Initialize_BaseBehavior_Fail_NoInitBind)
{
	MockBehavior mb;
	EXPECT_EQ(BehaviorStatus_Invalid, mb.GetStatus());

	mb.Tick(0.0f);

	EXPECT_EQ(BehaviorStatus_Invalid, mb.GetStatus());

}

TEST(AIBehavior, Test_Initialize_BaseBehavior_ActionBind)
{
	TestBehaviorCallee tCallee;
	auto ab = ACTIONBIND(&IBehaviorCallee::InitializeCb, &tCallee);
	//ab();

	MockBehavior* mb = new MockBehavior();
	mb->SetOnInitialize(&ab);

	EXPECT_EQ(BehaviorStatus_Invalid, mb->GetStatus());

	mb->Tick(0.0f);

	EXPECT_EQ(BehaviorStatus_Invalid, mb->GetStatus());

	delete mb; 
}

TEST(AIBehavior, Test_Selector_Returns_Success_One_Child)
{
	//SelectorBehavior sb = new SelectorBehavior();
}














