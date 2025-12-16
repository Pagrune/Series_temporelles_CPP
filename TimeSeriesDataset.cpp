#include "TimeSeriesDataset.h"
#include <cmath>
using namespace std;

TimeSeriesDataset::TimeSeriesDataset() : _znormalize(false), _isTrain(true), _maxlength(0), _numberOfSamples(0) {}

TimeSeriesDataset::TimeSeriesDataset(const vector<double>& data, const vector<int>& labels, bool znormalize, bool isTrain)
    : _data(data), _labels(labels), _znormalize(znormalize), _isTrain(isTrain) {
        if(_znormalize==true){
            this->znormalize();
        }
    }

void TimeSeriesDataset::znormalize(){

    int nombreElement=0;

    // moyenne
    double sumElement;
    for(int i=0; i< _data.size(); i++){
        sumElement+= _data[i];
        nombreElement ++;
    }
    double moyenne = sumElement/nombreElement;

    // ecart-type
    double sqrSum;
    double puissance = 2;
    for(int i=0; i< _data.size(); i++){
        sqrSum += (_data[i]-moyenne)*(_data[i]-moyenne);
    }
    double ecartType= sqrt(sqrSum/nombreElement);


    // réaffectation des datas
    for(int i=0; i< _data.size(); i++){
        _data[i]= (_data[i]-moyenne)/ecartType;
    }
}

double TimeSeriesDataset::euclideanDistance(const vector<double>& ts1, const vector<double>& ts2){
    double distance;
    double distSum;
    if(ts1.size()==ts2.size()){
        for(int i=0; i< ts1.size(); i++){
        distSum += (ts1[i]-ts2[i])*(ts1[i]-ts2[i]);
        }
        distance = sqrt(distSum);
        return distance;
    }
    else{
        return 0;
    }
}

double TimeSeriesDataset::DTW(const vector<double>& ts1, const vector<double>& ts2){
    double lengthTs1 = ts1.size();
    double lengthTs2 = ts2.size();

    vector<vector<double>> matrice(lengthTs1+1,vector<double> (lengthTs2+1, INFINITY));
    matrice[0][0]=0;

    for(int i=1; i <= lengthTs1; i++){
        for(int j=1; j <= lengthTs2; j++){
            double d = (ts1[i]-ts2[j])*(ts1[i]-ts2[j]);
            matrice[i][j] = d + min(matrice[i][j-1], matrice[i-1][j], matrice[i-1][j-1]);
        }
    }
    return sqrt(matrice[lengthTs1][lengthTs2]);
}