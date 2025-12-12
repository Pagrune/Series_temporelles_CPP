#include "StepGenerator.h"
#include <random>

StepGenerator::StepGenerator() : TimeSeriesGenerator() {}

StepGenerator::StepGenerator(const int seed) : TimeSeriesGenerator(seed) {}

vector<double> StepGenerator::generateTimeSeries(int length) {
    vector<double> series(length);

    srand(_seed); 

    double current = 0.0;

    for (int i = 0; i < length; i++) {
        // Avec 50% de chance, changer de valeur
        if (i > 0 && rand() % 2 == 0) {      // 0 ou 1 → 50/50
            current = rand() % 101;
        }

        series[i] = current;
    }

    return series;
}

