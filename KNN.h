#ifndef KNN_H
#define KNN_H

#include <string>
#include <vector>

using namespace std;


class KNN{
    private :
        int _k;
        string _similarity_measure;
    
    public :
        KNN();
        KNN(const int& k, const string& measure);

            // Returns accuracy as fraction of correctly classified series (0..1)
            double evaluate(const vector<int>& predicted, const vector<int>& actual) const;



};

#endif