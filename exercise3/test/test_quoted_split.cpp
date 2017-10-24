
#include "catch.hpp"

#include "../exercise3.hpp"

TEST_CASE("Empty strings are split as expected")
{
    const std::string s{};
    CHECK(quoted_split(s).empty());
}

TEST_CASE("Strings with one element are split as expected")
{
    const std::string s = "one";
    REQUIRE(quoted_split(s).size() == 1);
    CHECK(quoted_split(s).at(0) == s);
}

TEST_CASE("Strings with many elements are split as expected")
{
    const std::string s = "a,b,c,d,e,f";
    const std::vector<std::string> result{
            "a", "b", "c", "d", "e", "f"
    };
    CHECK(quoted_split(s) == result);
}

TEST_CASE("Quoted elements are treated as a single element")
{
    const std::string s = "\"a,b\",c,d";
    const std::vector<std::string> result{
            "a,b", "c", "d"
    };
    CHECK(quoted_split(s) == result);
}

