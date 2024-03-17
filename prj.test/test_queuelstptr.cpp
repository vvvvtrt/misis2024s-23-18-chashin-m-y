#include <queuelstptr/queuelstptr.hpp>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("QueueLstPtr ctor") {
	QueueLstPtr test;
	float test_num = 1.342;

	test.Push(test_num);


	CHECK_EQ(false, test.IsEmpty());
	CHECK_EQ(test_num, test.Top());

	QueueLstPtr test2(test);
	//CHECK_EQ(test2.Top(), test.Top());

	test.Pop();

	CHECK_EQ(true, test.IsEmpty());

	float test_num2 = 2.32423;
	test.Push(test_num2);
	test.Push(test_num);

	CHECK_EQ(test_num, test.Top());

	//test = test2;

	CHECK_EQ(test_num, test.Top());

	float test_num3 = 3.2424;
	float test_num4 = 0.235;

	test.Clear();
	CHECK_EQ(true, test.IsEmpty());

	test.Push(test_num);
	test.Push(test_num2);
	test.Push(test_num3);
	test.Push(test_num4);

	CHECK_EQ(test_num4, test.Top());
	test.Pop();
	CHECK_EQ(test_num, test.Top());
	test.Pop();
	CHECK_EQ(test_num2, test.Top());
	test.Pop();
	CHECK_EQ(test_num3, test.Top());
	test.Pop();
	CHECK_EQ(true, test.IsEmpty());
}
