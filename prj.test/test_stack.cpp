#include <stackarr/stackarr.hpp>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("stack ctor") {
	StackArr test;
	Complex test_num(1, 1);
	
	test.Push(test_num);
	

	CHECK_EQ(false, test.IsEmpty());
	CHECK_EQ(test_num, test.Top());

	test.Pop();

	CHECK_EQ(true, test.IsEmpty());
}
