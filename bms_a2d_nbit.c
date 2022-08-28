#include "stdio.h"
#include "bms.h"

int A2D_nBitArrayToValue(const int * nBitValues, int nBits)
{
    int a2dValue = 0;
    for (int index = 0; index < nBits; ++index)
    {
        a2dValue <<= 1;
        if (nBitValues[index] != 0)
        {
            a2dValue += 1;
        }
    }
    return a2dValue;
}
