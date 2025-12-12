#ifndef TIMESERIESGENERATOR_H
#define TIMESERIESGENERATOR_H

#include <vector>

using namespace std;

class TimeSeriesGenerator{
    protected:
        int _seed;

    public : 
        TimeSeriesGenerator();
        TimeSeriesGenerator(const int seed);



        virtual vector<double> generateTimeSeries(int _seed) = 0;


        static void printTimeSeries(const vector<double> myvector);
};


#endif