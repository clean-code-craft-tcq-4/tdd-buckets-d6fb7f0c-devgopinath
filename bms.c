#include "stdio.h"
#include "bms.h"

void toConsole(const char * msg)
{
    printf("%s\n", msg);
}

// void getOuput(char * output, DiscreteSamplesType sample)
// {
//     sprintf(output, "%d-%d, %d", sample.lowerLimit, sample.upperLimit, sample.nReadings);
// }

// void outputInfo(DiscreteSamplesType sample)
// {
//     char ouput[30];
//     getOuput(output, sample);
//     toConsole(output);
// }

// void processSamples(const int * samples, int nSamples)
// {
//     DiscreteSamplesType discreteSample;
//     int index;
    
//     toConsole(GET_HEADER);

//     discreteSample.lowerLimit = samples[0];
//     discreteSample.upperLimit = 0;
//     discreteSample.nReadings = 0;

//     index = 0;

//     while (index < nSamples)
//     {
//         if (discreteSample.lowerLimit == samples[index])
//         {
//             ++discreteSample.nReadings;
//         }
//         else
//         {

//         }
//         ++index;
//     }

//     if (nSamples == discreteSample.nReadings)
//     {
//         /*no two unique samples*/
//     }
//     else
//     {
//         outputInfo(discreteSample);
//     }
// }

char * currentSamples(void)
{
    char * msg = "4-5, 2";
    toConsole(GET_HEADER);
    toConsole(msg);

    return msg;
}
