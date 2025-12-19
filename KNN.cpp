#include "KNN.h"

using namespace std;

KNN::KNN(): _k(1), _similarity_measure("euclidean distance"){}

KNN::KNN(const int& k, const string& measure) : _k(k), _similarity_measure(measure) {}

double KNN::evaluate(const vector<int>& predicted, const vector<int>& actual) const {
	if(predicted.size() != actual.size() || predicted.empty()) return 0.0;
	int correct = 0;
	for(size_t i = 0; i < predicted.size(); ++i){
		if(predicted[i] == actual[i]) ++correct;
	}
	return static_cast<double>(correct) / static_cast<double>(predicted.size());
}
