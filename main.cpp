#include "TimeSeriesGenerator.h"
#include "StepGenerator.h"
#include "GaussianGenerator.h"
#include "SinWaveGenerator.h"

#include <vector>
#include <iostream>

using namespace std;

int main(){

    StepGenerator step(4);
    vector<double> SerieStep = step.generateTimeSeries(20);
    cout << "Step Generator \n";
    step.printTimeSeries(SerieStep);

    cout << "\n Gaussian Generator \n";

    GaussianGenerator gauss(10, 0.0, 1.0);
    vector<double> SerieGauss = gauss.generateTimeSeries(20);
    gauss.printTimeSeries(SerieGauss);

    cout << "\n Sin Wave Generator \n";
    SinWaveGenerator sinwave(25, 1.0, 0.05, 0.0);
    vector<double> SerieSin = sinwave.generateTimeSeries(20);
    sinwave.printTimeSeries(SerieSin);

    return 0;
}