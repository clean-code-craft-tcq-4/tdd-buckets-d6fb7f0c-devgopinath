#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "bms.h"
#include "test/catch.hpp"

TEST_CASE("current samples range")
{
    REQUIRE(strcmp(currentSamples(), "4-5, 2") == 0);
}

