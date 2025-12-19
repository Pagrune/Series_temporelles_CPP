#include "TimeSeriesGenerator.h"
#include "StepGenerator.h"
#include "GaussianGenerator.h"
#include "SinWaveGenerator.h"
#include "KNN.h"
#include "TimeSeriesDataset.h"

#include <vector>
#include <iostream>

using namespace std;

int main(){

    TimeSeriesDataset trainData(false, true), testData(false, false);

    GaussianGenerator gsg;
    SinWaveGenerator swg;
    StepGenerator stg;

    vector<double> gaussian1 = gsg.generateTimeSeries(11);
    trainData.addTimeSeries(gaussian1, 0);
    vector<double> gaussian2 = gsg.generateTimeSeries(11);
    trainData.addTimeSeries(gaussian2, 0);

    vector<double> sin1 = swg.generateTimeSeries(11);
    trainData.addTimeSeries(sin1, 1);
    vector<double> sin2 = swg.generateTimeSeries(11);
    trainData.addTimeSeries(sin2, 1);

    vector<double> step1 = stg.generateTimeSeries(11);
    trainData.addTimeSeries(step1, 2);
    vector<double> step2 = stg.generateTimeSeries(11);
    trainData.addTimeSeries(step2, 2);

    vector<int> ground_truth;
    testData.addTimeSeries(gsg.generateTimeSeries(11), 0);
    ground_truth.push_back(0);

    testData.addTimeSeries(swg.generateTimeSeries(11), 1);
    ground_truth.push_back(1);

    testData.addTimeSeries(stg.generateTimeSeries(11), 2);
    ground_truth.push_back(2);

    KNN knn_1(1, "dtw");

    cout << knn_1.evaluate(trainData, testData, ground_truth) << endl;

    KNN knn_2(2, "euclidean distance");

    cout << knn_2.evaluate(trainData, testData, ground_truth) << endl;

    KNN knn_3(3, "euclidean distance");
    cout << knn_3.evaluate(trainData, testData, ground_truth) << endl;
    
    // StepGenerator step(4);
    // vector<double> SerieStep = step.generateTimeSeries(20);
    // cout << "Step Generator \n";
    // step.printTimeSeries(SerieStep);

    // cout << "\n Gaussian Generator \n";

    // GaussianGenerator gauss(10, 0.0, 1.0);
    // vector<double> SerieGauss = gauss.generateTimeSeries(20);
    // gauss.printTimeSeries(SerieGauss);

    // cout << "\n Sin Wave Generator \n";
    // SinWaveGenerator sinwave(25, 1.0, 0.05, 0.0);
    // vector<double> SerieSin = sinwave.generateTimeSeries(20);
    // sinwave.printTimeSeries(SerieSin);



    return 0;
}