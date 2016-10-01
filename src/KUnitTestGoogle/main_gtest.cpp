/*
	Google test framework to test the various features like AI, Gameplay .. etc (Keep adding)
*/

#ifdef WIN32
#include <tchar.h>
#endif

#include "unittest_AIBehavior.h"

//#if defined(UNUSED) 



/*****************************/
/*Begin Sample Init programs*/

struct GoogleTest
{
	int m_initialized;
	GoogleTest()
	{
		m_initialized = 0;
		++m_initialized;
	}

	
};

bool static GetInitializedVal(int val)
{
	return val > 1;
}

struct GoogleTestFixture : public testing::Test
{
	GoogleTest* gTest;
	GoogleTestFixture()
	{
		gTest = new GoogleTest();
	}
	~GoogleTestFixture()
	{
		delete gTest;
	}
};

TEST_F(GoogleTestFixture, Test_GoogleTest_Struct)
{
	GoogleTest gt;
	EXPECT_EQ(1, gt.m_initialized);

	int initializedVal = 2;
	EXPECT_PRED1(GetInitializedVal, initializedVal);
}




/*****************************/
/*End of Sample Init programs*/

int _tmain(int argc, _TCHAR * argv[])
{
	testing::InitGoogleTest(&argc, argv);
	int result = RUN_ALL_TESTS();
	//getchar();
	return result;
}



//#endif
