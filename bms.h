#ifndef BMS_H
#define BMS_H

typedef struct
{
    int lowerLimit;
    int upperLimit;
    int count;
} IRangeCountType;

#define MAX_I_VALUE (200)
/* for range, it requires at least 2 continuous readings and one gap.
i.e., 3 continuous current iValues constitute one range
 */
#define MAX_NUM_RANGE   (MAX_I_VALUE / 3)

#define GET_HEADER  ("Range, Readings")


void PrepareRangeMsg(char * ouputMsg, const IRangeCountType * iRangeCount);
void LogRange(const IRangeCountType * iRangeCount);
void ProcessIValues(const int * iValues, int numValues);
int UpdateICounts(const int * iValues, int numValues, int * iCounts);
void InitRangeCount(IRangeCountType * iRangeCount);
void UpdateIRangeCounts(const int * iCounts, IRangeCountType * iRangeCount);
void ProcessRangeCounts(IRangeCountType * iRangeCount);

#endif // BMS_H
