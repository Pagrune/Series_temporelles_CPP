#include "TimeSeriesGenerator.h"
#include "StepGenerator.h"
#include "GaussianGenerator.h"

#include <vector>
#include <iostream>

using namespace std;

int main(){

    StepGenerator step;
    vector<double> SerieStep = step.generateTimeSeries(20);
    cout << "Step Generator \n";
    step.printTimeSeries(SerieStep);

    cout << "\n Gaussian Generator \n";

    GaussianGenerator gauss;
    vector<double> SerieGauss = gauss.generateTimeSeries(20);
    gauss.printTimeSeries(SerieGauss);

    return 0;
}