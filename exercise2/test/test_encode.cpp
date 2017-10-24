
#include "catch.hpp"

#include "../exercise2.hpp"

TEST_CASE("Empty strings can be encoded")
{
    const std::string s{};
    CHECK(encode(s) == s);
}

TEST_CASE("Encoding with zero shift works as expected")
{
    const std::string s = "THIS IS A TEST STRING";
    CHECK(encode(s, 0) == s);
}

TEST_CASE("Encoding with arbitrary shift works as expected")
{
    const std::string s = "THIS IS A TEST STRING :-)";
    const std::string result = "PDEO EO W PAOP OPNEJC :-)";
    CHECK(encode(s, 22) == result);
}
