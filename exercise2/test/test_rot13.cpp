
#include "catch.hpp"

#include "../exercise2.hpp"

TEST_CASE("Empty strings work as expected")
{
    const std::string s{};
    CHECK(rot13(s) == s);
}

TEST_CASE("Strings without special characters are rotated as expected")
{
    const std::string s = "THIS WORKS AS EXPECTED";
    const std::string result = "GUVF JBEXF NF RKCRPGRQ";
    CHECK(rot13(s) == result);
}

TEST_CASE("Strings of special characters are returned unchanged")
{
    const std::string s = "12345 +++++ 54321";
    CHECK(rot13(s) == s);
}

TEST_CASE("rot13 is its own inverse")
{
    const std::string s = "C++ LONDON UNIVERSITY IS AWESOME";
    CHECK(rot13(rot13(s)) == s);
}