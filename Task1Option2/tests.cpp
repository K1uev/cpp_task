#include "numbers.h"
#include <catch2/catch_all.hpp>
#include <vector>
#include <algorithm>

TEST_CASE("ReadNumbers")
{
    SECTION("Numbers reading")
    {
        char* argv[] = { (char*)"program", (char*)"2.0", (char*)"4", (char*)"-1.5" };
        auto result = ReadNumbers(4, argv);
        REQUIRE(result.size() == 3);
        REQUIRE(result[0] == 2.0);
        REQUIRE(result[1] == 4.0);
        REQUIRE(result[2] == -1.5);
    }

    SECTION("Invalid input")
    {
        char* argv[] = { (char*)"program", (char*)"abc", (char*)"4.5" };
        auto result = ReadNumbers(3, argv);
        REQUIRE(result.empty());
    }

    SECTION("Empty")
    {
        char* argv[] = { (char*)"program" };
        auto result = ReadNumbers(1, argv);
        REQUIRE(result.empty());
    }
}

TEST_CASE("ProcessNumbers")
{
    SECTION("Multiply each element by minimum value")
    {
        std::vector<double> input = { 2.0, 4.0, -1.5 };
        ProcessNumbers(input);
        REQUIRE(input[0] == Catch::Approx(-3.0));
        REQUIRE(input[1] == Catch::Approx(-6.0));
        REQUIRE(input[2] == Catch::Approx(2.25));
    }

    SECTION("Empty")
    {
        std::vector<double> input = {};
        ProcessNumbers(input);
        REQUIRE(input.empty());
    }

    SECTION("Single elem")
    {
        std::vector<double> input = { 5.0 };
        ProcessNumbers(input);
        REQUIRE(input[0] == Catch::Approx(25.0));
    }

    SECTION("Negative numbers")
    {
        std::vector<double> input = { -1.5, -2.0, -3.0 };
        ProcessNumbers(input);
        REQUIRE(input[0] == Catch::Approx(4.5));
        REQUIRE(input[1] == Catch::Approx(6.0));
        REQUIRE(input[2] == Catch::Approx(9.0));
    }
}

TEST_CASE("PrintSortedNumbers")
{
    SECTION("Sorts numbers correctly")
    {
        std::vector<double> input = { 3.0, 1.0, 2.0 };
        PrintSortedNumbers(input);
        REQUIRE(input[0] == 1.0);
        REQUIRE(input[1] == 2.0);
        REQUIRE(input[2] == 3.0);
    }

    SECTION("Empty")
    {
        std::vector<double> input = {};
        PrintSortedNumbers(input);
        REQUIRE(input.empty());
    }
}