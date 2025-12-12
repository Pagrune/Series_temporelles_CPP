#ifndef SINWAVEGENERATOR_H
#define SINWAVEGENERATOR_H

#include "TimeSeriesGenerator.h"

using namespace std;

class SinWaveGenerator : public TimeSeriesGenerator{
    private:
        float amplitude;
        float frequency;
        float phase;

    public :
        SinWaveGenerator();
        SinWaveGenerator(int seed, float a, float f, float p);

        vector<double> generateTimeSeries(int length) override;

    
};

#endif