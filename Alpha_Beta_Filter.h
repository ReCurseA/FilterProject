//
// Created by reuno on 03.10.2020.
//

#ifndef FILTER_ALPHA_BETA_FILTER_H
#define FILTER_ALPHA_BETA_FILTER_H

#include "Filter.h"

#include <cmath>
#include <complex>

class Alpha_Beta_Filter : public Filter {
public:
    Alpha_Beta_Filter();
    ~Alpha_Beta_Filter();

    void setTau(double T);

    double getTau();

    virtual void Filtration(const std::vector<std::complex<double> > &inputSignal, std::vector<std::complex<double> > &outputSignal);
private:
    double Tau;
    double alpha;
    double beta;
};

#endif //FILTER_ALPHA_BETA_FILTER_H
