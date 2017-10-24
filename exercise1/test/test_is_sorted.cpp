
#include "catch.hpp"

#include "../exercise1.hpp"

#include <random>

TEST_CASE("is_sorted() with empty vector")
{
    const std::vector<int> vec{};
    CHECK(is_sorted(vec));
}

TEST_CASE("is_sorted() with a simple sorted vector")
{
    const std::vector<int> vec{0, 1, 2, 3, 4};
    CHECK(is_sorted(vec));
}

TEST_CASE("is_sorted() with a simple unsorted vector")
{
    const std::vector<int> vec{2, 4, 3, 1, 0};
    CHECK_FALSE(is_sorted(vec));
}

TEST_CASE("is_sorted() with all equal values")
{
    const std::vector<int> vec{1, 1, 1, 1, 1};
    CHECK(is_sorted(vec));
}

TEST_CASE("is_sorted() with random vector")
{
    std::random_device rd{};
    std::mt19937 engine{rd()};
    std::uniform_int_distribution<int> dist{};

    std::vector<int> vec = [&] {
        std::vector<int> v(10'000);
        std::generate(v.begin(), v.end(), [&] {
            return dist(engine);
        });
        return v;
    }();

    // The chances of generating a sorted vector are so vanishingly small I
    // can't be bothered to check for it

    CHECK_FALSE(is_sorted(vec));

    std::sort(vec.begin(), vec.end());

    CHECK(is_sorted(vec));
}