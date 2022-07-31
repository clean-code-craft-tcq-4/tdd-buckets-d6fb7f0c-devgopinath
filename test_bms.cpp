#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "bms.h"
#include "test/catch.hpp"

TESTCASE("current samples range")
{
    REQUIRE(currentSamples() == "4-5, 2");
}

