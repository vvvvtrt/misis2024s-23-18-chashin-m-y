#include <bitset/bitset.hpp>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("bitset ctor") {
    BitSet b = BitSet();
    b.Fill(true);
    b[0]

    CHECK_EQ(0, d3[0]);
}
