
#include "catch.hpp"
#include "../exercise1.hpp"

#include <random>

// count_odd() tests

TEST_CASE("count_odd() with empty vector")
{
    const std::vector<int> vec{};
    CHECK(count_odd(vec) == 0);
}

TEST_CASE("count_odd() with no odd numbers")
{
    const std::vector<int> vec{2, 0, -428, 9999998, 42};
    CHECK(count_odd(vec) == 0);
}

TEST_CASE("count_odd() with all odd numbers")
{
    const std::vector<int> vec{3, -1, -429, 9999999, 43};
    CHECK(count_odd(vec) == vec.size());
}

TEST_CASE("count_odd() with a large vector of random numbers")
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

    const auto result = std::count_if(vec.begin(), vec.end(), [] (int i) {
        return i % 2 != 0;
    });

    CHECK(count_odd(vec) == result);
}