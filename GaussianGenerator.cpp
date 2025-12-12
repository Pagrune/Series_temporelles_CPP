#include "GaussianGenerator.h"

#include <cmath>
#include <cstdlib>

GaussianGenerator::GaussianGenerator(){};

GaussianGenerator::GaussianGenerator(int seed, float m, float e)
    : TimeSeriesGenerator(seed), moyenne(m), ecartType(e) {}



vector<double> GaussianGenerator::generateTimeSeries(int length) {
    vector<double> series(length);

    srand(_seed);

    for (int i = 0; i < length; i++) {
        // Méthode de Box-Muller pour générer une loi normale
        double u1 = (rand() + 1.0) / (RAND_MAX + 1.0);
        double u2 = (rand() + 1.0) / (RAND_MAX + 1.0);

        double z = sqrt(-2.0 * log(u1)) * cos(2 * M_PI * u2);

        // Transformation affine : moyenne + sigma * valeur normale
        series[i] = moyenne + ecartType * z;
    }

    return series;
}