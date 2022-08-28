#include "stdio.h"
#include "bms.h"

static void ToConsole(const char * msg)
{
    printf("%s\n", msg);
}

void PrepareRangeMsg(char * ouputMsg, const IRangeCountType * iRangeCount)
{
    sprintf(ouputMsg, "%d-%d, %d",
    iRangeCount->lowerLimit, iRangeCount->upperLimit, iRangeCount->count);
}

void LogRange(const IRangeCountType * iRangeCount)
{
    char ouputMsg[30];
    PrepareRangeMsg(ouputMsg, iRangeCount);
    ToConsole(ouputMsg);
}

void ProcessIValues(const int * iValues, int numValues)
{
    int iCounts[MAX_I_VALUE] = {0};
    IRangeCountType iRangeCounts[MAX_NUM_RANGE];
    (void)UpdateICounts(iValues, numValues, iCounts);
    UpdateIRangeCounts(iCounts, iRangeCounts);
    ProcessRangeCounts(iRangeCounts);
}

int UpdateICounts(const int * iValues, int numValues, int * iCounts)
{
    int iValue;
    int discardedIValues = 0;
    for (int index = 0; index < numValues; ++index)
    {
        iValue = iValues[index];
        if (iValue != 0)
        {
            if (iValue < MAX_I_VALUE)
            {
                ++iCounts[iValue];
            }
            else
            {
                ++discardedIValues;
            }
        }
    }
    return discardedIValues;
}

void InitRangeCount(IRangeCountType * iRangeCount)
{
    for (int index = 0; index < MAX_NUM_RANGE; ++index)
    {
        iRangeCount->count = 0;
        ++iRangeCount;
    }
}

void UpdateIRangeCounts(const int * iCounts, IRangeCountType * iRangeCount)
{
    int inRange = 0;

    InitRangeCount(iRangeCount);

    for (int iValue = 0; iValue < MAX_I_VALUE; ++iValue)
    {
        if (iCounts[iValue] != 0)
        {
            if (inRange == 0)
            {
                iRangeCount->lowerLimit = iValue;
            }
            else
            {
                iRangeCount->upperLimit = iValue;
            }
            iRangeCount->count += iCounts[iValue];
            ++inRange;
        }
        else
        {
            if (inRange != 0)
            {
                if (inRange > 1)
                {
                    ++iRangeCount;
                }
                iRangeCount->count = 0;
                inRange = 0;
            }
        }
    }
}

void ProcessRangeCounts(IRangeCountType * iRangeCount)
{
    ToConsole(GET_HEADER);
    for (int index = 0; index < MAX_NUM_RANGE; ++index)
    {
        if (iRangeCount->count != 0)
        {
            LogRange(iRangeCount);
        }
        else
        {
            break;
        }
        ++iRangeCount;
    }
}

