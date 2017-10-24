
#include "catch.hpp"

#include "../exercise1.hpp"

#include <random>

TEST_CASE("even_sum() with an empty vector")
{
    const std::vector<int> vec{};
    CHECK(even_sum(vec) == 0);
}

TEST_CASE("even_sum() with no even numbers")
{
    const std::vector<int> vec{-1, 3, 222223};
    CHECK(even_sum(vec) == 0);
}

TEST_CASE("even_sum() with one even number")
{
    const std::vector<int> vec{-1, 273, -40};
    CHECK(even_sum(vec) == -40);
}

TEST_CASE("even_sum() with a vector of random numbers")
{
    // We have to be very careful here not to overflow an int
    std::random_device rd{};
    std::mt19937 engine{rd()};
    std::uniform_int_distribution<int> dist{-1000, 1000};

    const std::vector<int> vec = [&] {
        std::vector<int> v(100);
        std::generate(v.begin(), v.end(), [&] {
            return dist(engine);
        });
        return v;
    }();

    const int result = [&] {
        int s = 0;
        for (auto i : vec) {
            s += (i % 2 == 0) ? i : 0;
        }
        return s;
    }();

    CHECK(even_sum(vec) == result);
}