#include <dynarr/dynarr.hpp>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("dynarr ctor") {
    DynArr d1;
    CHECK_EQ(0, d1.size());

    DynArr d2(4);
    CHECK_EQ(4, d2.size());
    CHECK_EQ(0, d2[0]);
    CHECK_EQ(0, d2[1]);
    CHECK_EQ(0, d2[2]);
    CHECK_EQ(0, d2[3]);

    d2[0] = 0;
    d2[1] = 1;
    d2[2] = 2;
    d2[3] = 3;
    CHECK_EQ(0, d2[0]);
    CHECK_EQ(1, d2[1]);
    CHECK_EQ(2, d2[2]);
    CHECK_EQ(3, d2[3]);

    DynArr d3(d2);
    CHECK_EQ(4,d3.size());
    CHECK_EQ(0, d3[0]);
    CHECK_EQ(1, d3[1]);
    CHECK_EQ(2, d3[2]);
    CHECK_EQ(3, d3[3]);
    d3[0] = 10;
    CHECK_EQ(10, d3[0]);
    CHECK_EQ(0, d2[0]);
    d3[0] = 0;

    d3.resize(8);
    d3[5] = 10;
    CHECK_EQ(8, d3.size());
    CHECK_EQ(0, d3[0]);
    CHECK_EQ(1, d3[1]);
    CHECK_EQ(2, d3[2]);
    CHECK_EQ(3, d3[3]);
    CHECK_EQ(0, d3[4]);
    CHECK_EQ(10, d3[5]);
    CHECK_EQ(0, d3[6]);
    CHECK_EQ(0, d3[7]);
    CHECK_THROWS(d3[8]);

    d3.resize(4);
    CHECK_EQ(4, d3.size());
    CHECK_EQ(0, d3[0]);
    CHECK_EQ(1, d3[1]);
    CHECK_EQ(2, d3[2]);
    CHECK_EQ(3, d3[3]);
    CHECK_THROWS(d3[4]);

    d3.resize(6);
    CHECK_EQ(6, d3.size());
    CHECK_EQ(0, d3[0]);
    CHECK_EQ(1, d3[1]);
    CHECK_EQ(2, d3[2]);
    CHECK_EQ(3, d3[3]);
    CHECK_EQ(0, d3[4]);
    CHECK_EQ(0, d3[5]);
    CHECK_THROWS(d3[6]);
    
    d1 = d3;
    CHECK_EQ(6, d1.size());
    CHECK_EQ(0, d1[0]);
    CHECK_EQ(1, d1[1]);
    CHECK_EQ(2, d1[2]);
    CHECK_EQ(3, d1[3]);
    CHECK_EQ(0, d1[4]);
    CHECK_EQ(0, d1[5]);

    d1 = d2;
    CHECK_EQ(4, d1.size());
    CHECK_EQ(0, d1[0]);
    CHECK_EQ(1, d1[1]);
    CHECK_EQ(2, d1[2]);
    CHECK_EQ(3, d1[3]);

    CHECK_THROWS(DynArr(-5));
    CHECK_THROWS(d1.resize(-2));
    CHECK_THROWS(DynArr(0));
    CHECK_THROWS(d1.resize(0));
    CHECK_THROWS(d1[-10]);
    CHECK_THROWS(d1[80]);
}
