
#include "catch.hpp"

#include "../exercise2.hpp"

TEST_CASE("A -> N")
{
    CHECK(shift_char('A') == 'N');
}

TEST_CASE("N -> A")
{
    CHECK(shift_char('N') == 'A');
}

TEST_CASE("Other characters are unchanged")
{
    CHECK(shift_char(' ') == ' ');
    CHECK(shift_char('1') == '1');
    CHECK(shift_char('+') == '+');
}