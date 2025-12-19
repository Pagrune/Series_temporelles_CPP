#ifndef TIMESERIESDATASET_H
#define TIMESERIESDATASET_H

#include <vector>


using namespace std;

class TimeSeriesDataset{
    private:
        bool _znormalize;
        bool _isTrain;
        vector<vector<double>> _data;
        vector<int> _labels;
        int _maxlength;
        int _numberOfSamples;
    
    public: 
        // Constructors
        TimeSeriesDataset();
        TimeSeriesDataset(bool znormalize, bool isTrain);

        void znormalize(vector<double> data);

        void addTimeSeries(vector<double> data, int label);

        double euclideanDistance(const vector<double>& ts1, const vector<double>& ts2);

        double DTW(const vector<double>& ts1, const vector<double>& ts2);
};


#endif