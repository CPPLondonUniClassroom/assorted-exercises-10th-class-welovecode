
#include "catch.hpp"

#include "../exercise1.hpp"

#include <random>

TEST_CASE("Empty vector")
{
    const std::vector<int> vec{};
    CHECK(largest_div_by_three(vec) == 0);
}

TEST_CASE("No elements divisible by 3")
{
    const std::vector<int> vec{2, 5, 8, -9998};
    CHECK(largest_div_by_three(vec) == 0);
}

TEST_CASE("One element divisible by 3")
{
    const std::vector<int> vec{3, 2, 5, 8, -9998};
    CHECK(largest_div_by_three(vec) == 3);
}

TEST_CASE("All divisible by 3")
{
    const std::vector<int> vec{3, 99, 27, 54, -108};
    CHECK(largest_div_by_three(vec) == 99);
}

TEST_CASE("All negative")
{
    const std::vector<int> vec{-3, -99, -27, -54, -108};
    CHECK(largest_div_by_three(vec) == -3);
}

TEST_CASE("Random numbers")
{
    std::random_device rd{};
    std::mt19937 engine{rd()};
    std::uniform_int_distribution<int> dist{-100'000, 100'000};

    const std::vector<int> vec = [&] {
        std::vector<int> v(10'000);
        std::generate(v.begin(), v.end(), [&] {
            return dist(engine);
        });
        return v;
    }();

    const int result = [&] {
        std::vector<int> temp;
        std::copy_if(vec.begin(), vec.end(), std::back_inserter(temp), [] (int i) {
            return i % 3 == 0;
        });
        if (temp.empty()) {
            return 0;
        }
        return *std::max_element(temp.cbegin(), temp.cend());
    }();

    CHECK(largest_div_by_three(vec) == result);
}