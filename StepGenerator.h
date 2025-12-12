#ifndef STEPGENERATOR_H
#define STEPGENERATOR_H

#include "TimeSeriesGenerator.h"

class StepGenerator : public TimeSeriesGenerator{
    public:
        StepGenerator();
        StepGenerator(const int seed);
        
        vector<double> generateTimeSeries(int length) override;
};

#endif