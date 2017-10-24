
#include "catch.hpp"

#include "../exercise1.hpp"

#include <random>

TEST_CASE("copy_if_divisible_by() with an empty vector")
{
    const std::vector<int> vec{};
    CHECK(copy_if_divisible_by(vec, 1).empty());
}

TEST_CASE("copy_if_divisible_by() with a p == 1")
{
    const std::vector<int> vec{99, 102, -42, 999'999'999};
    CHECK(copy_if_divisible_by(vec, 1) == vec);
}

TEST_CASE("copy_if_divisible_by() with p == 3")
{
    const std::vector<int> vec{99, 0, -47, 1'000'000'008};
    const std::vector<int> result{99, 0, 1'000'000'008};
    CHECK(copy_if_divisible_by(vec, 3) == result);
}

TEST_CASE("copy_if_divisible_by() with a random vector")
{
    std::random_device rd{};
    std::mt19937 engine{rd()};
    std::uniform_int_distribution<int> dist{};

    const std::vector<int> vec = [&] {
        std::vector<int> v(10'000);
        std::generate(v.begin(), v.end(), [&] {
            return dist(engine);
        });
        return v;
    }();

    const auto out = [&] {
        std::vector<int> v;
        std::copy_if(vec.begin(), vec.end(), std::back_inserter(v), [] (int i) {
            return i % 7 == 0;
        });
        return v;
    }();

    REQUIRE(copy_if_divisible_by(vec, 7) == out);
}