#include "SinWaveGenerator.h"
#include <cmath>

SinWaveGenerator::SinWaveGenerator() : TimeSeriesGenerator() {}

SinWaveGenerator::SinWaveGenerator(int seed, float a, float f, float p)
    : TimeSeriesGenerator(seed), amplitude(a), frequency(f), phase(p) {}

vector<double> SinWaveGenerator::generateTimeSeries(int length) {
    vector<double> series(length);

    for (int i = 0; i < length; i++) {
        series[i] = amplitude * sin(frequency* i + phase);
    }
    return series;
}