#ifndef TIMESERIESDATASET_H
#define TIMESERIESDATASET_H

#include <vector>


using namespace std;

class TimeSeriesDataset{
    private:
        bool _znormalize;
        bool _isTrain;
        vector<double> _data;
        vector<int> _labels;
        int _maxlength;
        int _numberOfSamples;
    
    public: 
        // Constructors
        TimeSeriesDataset();
        TimeSeriesDataset(const vector<double>& data, const vector<int>& labels, bool znormalize=false, bool isTrain=true);

        void znormalize();

        double euclideanDistance(const vector<double>& ts1, const vector<double>& ts2);
};


#endif