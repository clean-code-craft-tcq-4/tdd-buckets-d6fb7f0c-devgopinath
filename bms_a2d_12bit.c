#include "stdio.h"
#include "bms.h"

int A2D_12BitArrayToValue(const int * a2d_12bitValues)
{
    int a2d12bitValue = 0;
    for (int index = 0; index < 12; ++index)
    {
        a2d12bitValue <<= 1;
        if (a2d_12bitValues[index] != 0)
        {
            a2d12bitValue += 1;
        }
    }
    return a2d12bitValue;
}
