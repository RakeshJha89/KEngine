#pragma once
#include "string"
#include "gtest/gtest.h"
#include "AICommon.h"
#include "AIBehaviorMocks/AIMockBehavior.h"

/*Examples*/

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
	auto ab = ACTIONBIND(&ActionBindTest::PrintHelloWorld, bindTest);
	ab();	//Execute.
}

TEST(AIAction, Test_ActionBind_Pass_Param)
{
	auto ab = ACTIONBIND(&ActionBindTest::PrintPassedParam, bindTest);
	ab("Hello World");
}

TEST(AIBehavior, Test_Initialize_BaseBehavior_Fail_NoInitBind)
{
	MockBehavior* mb = new MockBehavior();
	EXPECT_EQ(BehaviorStatus_Invalid, mb->GetStatus());

	mb->Tick(0.0f);

	EXPECT_EQ(BehaviorStatus_Invalid, mb->GetStatus());

	delete mb;
}

BehaviorStatus OnInitialize()
{
	return BehaviorStatus_Success;
}

TEST(AIBehavior, Test_Initialize_BaseBehavior_ActionBind)
{
	//auto ab = ACTIONBIND(OnInitialize);
	auto ab = ACTIONBIND(&ActionBindTest::PrintPassedParam, bindTest);
	ab("Hello World");

	MockBehavior* mb = new MockBehavior();
	mb->SetOnInitialize(&ab);

	EXPECT_EQ(BehaviorStatus_Invalid, mb->GetStatus());

	mb->Tick(0.0f);

	EXPECT_EQ(BehaviorStatus_Running, mb->GetStatus());

	delete mb; 
}

TEST(AIBehavior, Test_Selector_Returns_Success_One_Child)
{
	//SelectorBehavior sb = new SelectorBehavior();
}













