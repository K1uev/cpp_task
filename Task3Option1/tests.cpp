#include "WordCount.h"
#include <catch2/catch_test_macros.hpp>
#include <sstream>
#include <map>
#include <string>

TEST_CASE("CountWordsFromStream")
{
    SECTION("Simple string")
    {
        std::istringstream input("€блоко €блоко груша");
        WordCountMap result = CountWordsFromStream(input);

        REQUIRE(result.size() == 2);
        REQUIRE(result.find("€блоко")->second == 2);
        REQUIRE(result.find("груша")->second == 1);
    }

    SECTION("Different cases")
    {
        std::istringstream input("груша дын€ яблоко €блоко груша");
        WordCountMap result = CountWordsFromStream(input);

        REQUIRE(result.size() == 4);
        REQUIRE(result.find("груша")->second == 2);
        REQUIRE(result.find("дын€")->second == 1);
        REQUIRE(result.find("яблоко")->second == 1);
        REQUIRE(result.find("€блоко")->second == 1);
    }

    SECTION("Numbers")
    {
        std::istringstream input("3 1 2 3 2 3");
        WordCountMap result = CountWordsFromStream(input);

        REQUIRE(result.size() == 3);
        REQUIRE(result.find("1")->second == 1);
        REQUIRE(result.find("2")->second == 2);
        REQUIRE(result.find("3")->second == 3);
    }

    SECTION("Empty")
    {
        std::istringstream input("");
        WordCountMap result = CountWordsFromStream(input);

        REQUIRE(result.empty());
    }

    SECTION("String with whitespace")
    {
        std::istringstream input("     \n\t  \n   ");
        WordCountMap result = CountWordsFromStream(input);

        REQUIRE(result.empty());
    }

    SECTION("Single word")
    {
        std::istringstream input("hello");
        WordCountMap result = CountWordsFromStream(input);

        REQUIRE(result.size() == 1);
        REQUIRE(result.find("hello")->second == 1);
    }

    SECTION("Add punctuation")
    {
        std::istringstream input("hello, world! hello!");
        WordCountMap result = CountWordsFromStream(input);

        REQUIRE(result.size() == 3);
        REQUIRE(result.find("hello,")->second == 1);
        REQUIRE(result.find("world!")->second == 1);
        REQUIRE(result.find("hello!")->second == 1);
    }
}
