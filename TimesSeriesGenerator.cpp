#include "TimeSeriesGenerator.h"
#include <vector>
#include <iostream>


using namespace std;

TimeSeriesGenerator::TimeSeriesGenerator(){};

TimeSeriesGenerator::TimeSeriesGenerator(const int seed): _seed(seed){};

void TimeSeriesGenerator::printTimeSeries(const vector<double> myVector){
    for (const auto& value : myVector) {
        cout << value << " ";
    }
    cout << endl;

}