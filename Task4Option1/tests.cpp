#include "crossSet.h"
#include <catch2/catch_test_macros.hpp>
#include <set>
#include <sstream>
#include <stdexcept>

TEST_CASE("SumOfDigits")
{
    SECTION("Single digit number")
    {
        REQUIRE(SumOfDigits(5) == 5);
    }

    SECTION("Multiple digit number")
    {
        REQUIRE(SumOfDigits(123) == 6);
    }
}

TEST_CASE("CreateSetDivisibleByDigitSum")
{
    SECTION("N = 10")
    {
        std::set<int> result = CreateSetDivisibleByDigitSum(10);
        std::set<int> expected = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        REQUIRE(result == expected);
    }

    SECTION("N = 20")
    {
        std::set<int> result = CreateSetDivisibleByDigitSum(20);
        std::set<int> expected = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 18, 20 };
        REQUIRE(result == expected);
    }

    SECTION("N = 1")
    {
        std::set<int> result = CreateSetDivisibleByDigitSum(1);
        std::set<int> expected = { 1 };
        REQUIRE(result == expected);
    }

    SECTION("N = 0")
    {
        std::set<int> result = CreateSetDivisibleByDigitSum(0);
        REQUIRE(result.empty());
    }
}

TEST_CASE("CreateSetEvenDigitSum")
{
    SECTION("N = 10")
    {
        std::set<int> result = CreateSetEvenDigitSum(10);
        std::set<int> expected = { 2, 4, 6, 8 };
        REQUIRE(result == expected);
    }

    SECTION("N = 5")
    {
        std::set<int> result = CreateSetEvenDigitSum(5);
        std::set<int> expected = { 2, 4 };
        REQUIRE(result == expected);
    }

    SECTION("N = 20")
    {
        std::set<int> result = CreateSetEvenDigitSum(20);
        std::set<int> expected = { 2, 4, 6, 8, 11, 13, 15, 17, 19, 20 };
        REQUIRE(result == expected);
    }

    SECTION("N = 1")
    {
        std::set<int> result = CreateSetEvenDigitSum(1);
        REQUIRE(result.empty());
    }
}

TEST_CASE("CrossSet")
{
    SECTION("Normal")
    {
        std::set<int> set1 = { 1, 2, 3, 4, 5 };
        std::set<int> set2 = { 2, 4, 6, 8 };
        std::set<int> result = CrossSet(set1, set2);
        std::set<int> expected = { 2, 4 };
        REQUIRE(result == expected);
    }

    SECTION("No cross")
    {
        std::set<int> set1 = { 1, 3, 5 };
        std::set<int> set2 = { 2, 4, 6 };
        std::set<int> result = CrossSet(set1, set2);
        REQUIRE(result.empty());
    }

    SECTION("One empty set")
    {
        std::set<int> set1 = { 1, 2, 3 };
        std::set<int> set2 = {};
        std::set<int> result = CrossSet(set1, set2);
        REQUIRE(result.empty());
    }

    SECTION("Empty sets")
    {
        std::set<int> set1 = {};
        std::set<int> set2 = {};
        std::set<int> result = CrossSet(set1, set2);
        REQUIRE(result.empty());
    }
}

TEST_CASE("Full tests")
{
    SECTION("N=10")
    {
        std::set<int> set1 = CreateSetDivisibleByDigitSum(10);
        std::set<int> set2 = CreateSetEvenDigitSum(10);
        std::set<int> intersection = CrossSet(set1, set2);

        REQUIRE(set1.size() == 10);
        REQUIRE(set2.size() == 4);
        REQUIRE(intersection.size() == 4);
        REQUIRE(intersection == std::set<int>{2, 4, 6, 8});
    }

    SECTION("N=20")
    {
        std::set<int> set1 = CreateSetDivisibleByDigitSum(20);
        std::set<int> set2 = CreateSetEvenDigitSum(20);
        std::set<int> intersection = CrossSet(set1, set2);

        REQUIRE(intersection == std::set<int>{2, 4, 6, 8, 20});
    }
}
