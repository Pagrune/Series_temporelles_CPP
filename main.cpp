#include "TimeSeriesGenerator.h"
#include "StepGenerator.h"
#include <vector>
#include <iostream>

using namespace std;

int main(){

    StepGenerator step;
    vector<double> SerieStep = step.generateTimeSeries(20);
    step.printTimeSeries(SerieStep);

    return 0;
}