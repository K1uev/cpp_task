#include "trimBlanks.h"
#include <catch2/catch_test_macros.hpp>
#include <string>

TEST_CASE("TrimBlanks")
{
    SECTION("Empty")
    {
        std::string input = "";
        std::string result = TrimBlanks(input);
        REQUIRE(result == "");
    }

    SECTION("Normal string")
    {
        std::string input = "hello";
        std::string result = TrimBlanks(input);
        REQUIRE(result == "hello");
    }

    SECTION("Spaces at the beginning")
    {
        std::string input = "   hello";
        std::string result = TrimBlanks(input);
        REQUIRE(result == "hello");
    }

    SECTION("Spaces at the end")
    {
        std::string input = "hello   ";
        std::string result = TrimBlanks(input);
        REQUIRE(result == "hello");
    }

    SECTION("Spaces at the beginning and at the end")
    {
        std::string input = "   hello   ";
        std::string result = TrimBlanks(input);
        REQUIRE(result == "hello");
    }

    SECTION("Only space")
    {
        std::string input = "     ";
        std::string result = TrimBlanks(input);
        REQUIRE(result == "");
    }

    SECTION("Multiple words with spaces")
    {
        std::string input = "   hello, world   ";
        std::string result = TrimBlanks(input);
        REQUIRE(result == "hello, world");
    }

    SECTION("Tabs and newlines")
    {
        std::string input = "\t\n hello \t\n";
        std::string result = TrimBlanks(input);
        REQUIRE(result == "hello");
    }

    SECTION("String with spaces between words")
    {
        std::string input = "hello world";
        std::string result = TrimBlanks(input);
        REQUIRE(result == "hello world");
    }

    SECTION("Mixed whitespace")
    {
        std::string input = "  \t\n\r hello \t\n\r  ";
        std::string result = TrimBlanks(input);
        REQUIRE(result == "hello");
    }
}