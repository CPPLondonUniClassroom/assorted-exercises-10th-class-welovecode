
#include "catch.hpp"

#include "../exercise2.hpp"

TEST_CASE("Empty strings can be decoded")
{
    const std::string s{};
    CHECK(decode(s) == s);
}

TEST_CASE("Decoding with zero shift works as expected")
{
    const std::string s = "THIS IS A TEST STRING";
    CHECK(encode(s, 0) == s);
}

TEST_CASE("Decoding with arbitrary shift works as expected")
{
    const std::string s = "PDEO EO W PAOP OPNEJC :-)";
    const std::string result = "THIS IS A TEST STRING :-)";
    CHECK(encode(s, 22) == result);
}
