#ifndef BMS_H
#define BMS_H

typedef struct
{
    unsigned int nReadings;
    unsigned int lowerLimit;
    unsigned int upperLimit;
} DiscreteSamplesType;

#define GET_HEADER  ("Range, Readings")


char * currentSamples(void);


#endif // BMS_H
