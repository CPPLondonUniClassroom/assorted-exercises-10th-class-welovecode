
#include "catch.hpp"
#include "../exercise1.hpp"

TEST_CASE("2 is an even number")
{
    CHECK(is_even(2));
}

TEST_CASE("3 is not an even number")
{
    CHECK_FALSE(is_even(3));
}

TEST_CASE("0 is an even number")
{
    CHECK(is_even(0));
}

TEST_CASE("-66667 is not an even number")
{
    CHECK(!is_even(-66667));
}
