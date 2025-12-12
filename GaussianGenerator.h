#ifndef GAUSSIANGENERATOR_H
#define GAUSSIANGENERATOR_H

#include "TimeSeriesGenerator.h"

using namespace std;

class GaussianGenerator : public TimeSeriesGenerator{
    private:
        float moyenne;
        float ecartType;
    
};

#endif