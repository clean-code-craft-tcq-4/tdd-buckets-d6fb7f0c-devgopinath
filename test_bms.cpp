#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "bms.h"
#include "test/catch.hpp"

void CheckCounts(const int * iValues, int numValues, int * expectediCounts)
{
    int iCounts[MAX_I_VALUE] = {0};

    REQUIRE(UpdateICounts(iValues, numValues, iCounts) == 0);
    for (int index = 0; index < MAX_I_VALUE; ++index)
    {
        REQUIRE(iCounts[index] == expectediCounts[index]);
    }
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

TEST_CASE("check counts")
{
    int iValues[] = {4,5};
    int numValues = 2;
    int expectediCounts[MAX_I_VALUE] = {0};
    expectediCounts[4] = 1;
    expectediCounts[5] = 1;

    CheckCounts(iValues, numValues, expectediCounts);
}

TEST_CASE("check counts 1")
{
    int iValues[] = {3,4,5,7,6,3};
    int numValues = 6;
    int expectediCounts[MAX_I_VALUE] = {0};
    expectediCounts[3] = 2;
    expectediCounts[4] = 1;
    expectediCounts[5] = 1;
    expectediCounts[6] = 1;
    expectediCounts[7] = 1;

    CheckCounts(iValues, numValues, expectediCounts);
}

TEST_CASE("check range counts")
{
    IRangeCountType iRangeCounts[MAX_NUM_RANGE];
    int iCounts[MAX_I_VALUE] = {0};
    iCounts[4] = 1;
    iCounts[5] = 1;
    UpdateIRangeCounts(iCounts, iRangeCounts);
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

TEST_CASE("Complete test case")
{
    int iValues[] = {3,4,5,7,6,3};
    int numValues = 6;
    ProcessIValues(iValues, numValues);
}

TEST_CASE("a2d 12-bit array")
{
    {
        int a2dBitValues[] = {0,0,0,0, 0,0,0,0, 0,0,0,0};
        int exptectedValue = 0;
        REQUIRE(A2D_12BitArrayToValue(a2dBitValues) == exptectedValue);
    }
    {
        int a2dBitValues[] = {0,0,0,0, 0,0,0,0, 0,0,0,1};
        int exptectedValue = 1;
        REQUIRE(A2D_12BitArrayToValue(a2dBitValues) == exptectedValue);
    }
    {
        int a2dBitValues[] = {0,1,1,1, 1,1,0,1, 0,0,0,0};
        int exptectedValue = 2000;
        REQUIRE(A2D_12BitArrayToValue(a2dBitValues) == exptectedValue);
    }
    {
        int a2dBitValues[] = {1,1,1,1, 1,1,1,1, 1,1,1,0};
        int exptectedValue = 4094;
        REQUIRE(A2D_12BitArrayToValue(a2dBitValues) == exptectedValue);
    }
    {
        int a2dBitValues[] = {1,1,1,1, 1,1,1,1, 1,1,1,1};
        int exptectedValue = 4095;
        REQUIRE(A2D_12BitArrayToValue(a2dBitValues) == exptectedValue);
    }
}

TEST_CASE("a2d 10-bit array")
{
    {
        int a2dBitValues[] = {0,0, 0,0,0,0, 0,0,0,0};
        int exptectedValue = 0;
        REQUIRE(A2D_10BitArrayToValue(a2dBitValues) == exptectedValue);
    }
    {
        int a2dBitValues[] = {0,0, 0,0,0,0, 0,0,0,1};
        int exptectedValue = 1;
        REQUIRE(A2D_10BitArrayToValue(a2dBitValues) == exptectedValue);
    }
    {
        int a2dBitValues[] = {0,1, 1,1,1,1, 1,1,1,1};
        int exptectedValue = 511;
        REQUIRE(A2D_10BitArrayToValue(a2dBitValues) == exptectedValue);
    }
    {
        int a2dBitValues[] = {1,1, 1,1,1,1, 1,1,1,0};
        int exptectedValue = 1022;
        REQUIRE(A2D_10BitArrayToValue(a2dBitValues) == exptectedValue);
    }
    {
        int a2dBitValues[] = {1,1, 1,1,1,1, 1,1,1,1};
        int exptectedValue = 1023;
        REQUIRE(A2D_10BitArrayToValue(a2dBitValues) == exptectedValue);
    }
}
