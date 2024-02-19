#include <queuelst/queuelst.hpp>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("queuelst ctor") {
	QueueLst test;
	Complex test_num(1, 1);

	test.Push(test_num);


	CHECK_EQ(false, test.IsEmpty());
	CHECK_EQ(test_num, test.Top());

	QueueLst test2(test);
	CHECK_EQ(test2.Top(), test.Top());

	test.Pop();

	CHECK_EQ(true, test.IsEmpty());

	Complex test_num2(2, 2);
	test.Push(test_num2);
	test.Push(test_num);

	CHECK_EQ(test_num2, test.Top());

	test = test2;

	CHECK_EQ(test_num, test.Top());
}
