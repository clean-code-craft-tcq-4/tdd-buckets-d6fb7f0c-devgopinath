#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "bms.h"
#include "test/catch.hpp"

TEST_CASE("check range counts")
{
    IRangeCountType iRangeCounts[MAX_NUM_RANGE];
    int iCounts[MAX_I_VALUE] = {0,0,0,0,1,1};
    UpdateIRangeCounts(iCounts, &iRangeCounts);
    REQUIRE(iRangeCounts[0].lowerLimit == 4);
    REQUIRE(iRangeCounts[0].upperLimit == 5);
    REQUIRE(iRangeCounts[0].count == 2);
}

TEST_CASE("output message format")
{
    IRangeCountType iRangeCount;
    char outputMsg[30];
    iRangeCount.lowerLimit = 4;
    iRangeCount.upperLimit = 7;
    iRangeCount.count = 9;
    PrepareRangeMsg(outputMsg, &iRangeCount);
    REQUIRE(strcmp(outputMsg, "4-7, 9") == 0);
}

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

// TEST_CASE("current samples range")
// {
//     int iSamples[] = {4,5};
//     int nSamples = sizeof(iSamples);
//     REQUIRE(strcmp(currentSamples((const int *)iSamples, nSamples), "4-5, 2") == 0);
// }

