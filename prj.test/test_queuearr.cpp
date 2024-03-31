#include <queuearr/queuearr.hpp>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("queuearr ctor") {
	QueueArr test;
	Complex test_num(1, 1);

	test.Push(test_num);


	CHECK_EQ(false, test.IsEmpty());
	CHECK_EQ(test_num, test.Top());

	QueueArr test2(test);
	CHECK_EQ(test2.Top(), test.Top());

	test.Pop();

	CHECK_EQ(true, test.IsEmpty());

	Complex test_num2(2, 2);
	test.Push(test_num2);
	test.Push(test_num);

	CHECK_EQ(test_num2, test.Top());

	test = test2;

	CHECK_EQ(test_num, test.Top());

	Complex test_num3(0, 0);
	Complex test_num4(0, 2);

	test.Clear();
	CHECK_EQ(true, test.IsEmpty());

	test.Push(test_num);
	test.Push(test_num2);
	test.Push(test_num3);
	test.Push(test_num4);

	CHECK_EQ(test_num, test.Top());
	test.Pop();
	CHECK_EQ(test_num2, test.Top());
	test.Pop();
	CHECK_EQ(test_num3, test.Top());
	test.Pop();
	CHECK_EQ(test_num4, test.Top());
	test.Pop();
	CHECK_EQ(true, test.IsEmpty());
}
