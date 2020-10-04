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

    double getAlpha();

    double getBeta();

    void init(const std::complex<double> &inputFirstElement);

    void reset();

    // void Filtration(const std::vector<std::complex<double> > &inputSignal, std::vector<std::complex<double> > &outputSignal);

    std::complex<double> Filtration(std::complex<double> &inputSignal);
private:
    double Tau;
    double alpha;
    double beta;

    std::complex<double> xFiltered;
    std::complex<double> xFiltered_dot;

    void setAlphaBeta();
};

#endif //FILTER_ALPHA_BETA_FILTER_H
