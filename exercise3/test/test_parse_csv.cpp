
#include "catch.hpp"

#include "../exercise3.hpp"

const std::string unquoted = R"(first,second,third,
1,2,3
4,5,6)";

const std::string quoted = R"(first,second,third,
1,2,3
"4,5",6,7)";

TEST_CASE("Unquoted CSV files can be parsed as expected")
{
    std::istringstream ss(unquoted);
    const auto csv = parse_csv(ss);
    const auto result = std::vector<std::vector<std::string>>{
        {"first", "second", "third"},
        {"1", "2", "3"},
        {"4", "5", "6"}
    };
    CHECK(csv.lines == result);
}

TEST_CASE("Quoted CSV files can be parsed as expected")
{
    std::istringstream ss(quoted);
    const auto csv = parse_csv(ss);
    const auto result = std::vector<std::vector<std::string>>{
        {"first", "second", "third"},
        {"1", "2", "3"},
        {"4,5", "6", "7"}
    };
    CHECK(csv.lines == result);
}