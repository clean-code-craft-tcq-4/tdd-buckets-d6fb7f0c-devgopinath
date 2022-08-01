#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "bms.h"
#include "test/catch.hpp"

/*
Input ouput
{3}
{3,3}
{3,4} "3-4, 2"
{3,3,4} "3-4, 3"
{3,4,5} "3-5, 3"
{3,4,5,7} "3-5, 3"
{3,4,5,7,7} "3-5, 3"
{3,4,5,7,6} "3-5, 3" "6-7, 2"
{3,4,5,7,6,3} "3-5, 3" "6-7, 2"
*/

TEST_CASE("current samples range")
{
    int iSamples[] = {4,5};
    int nSamples = sizeof(iSamples);
    REQUIRE(strcmp(currentSamples((const int *)iSamples, nSamples), "4-5, 2") == 0);
}

