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

    void Alpha_Beta_Filter::setAlphaBeta();

    double getTau();

    double Alpha_Beta_Filter::getAlpha();

    double Alpha_Beta_Filter::getBeta();

    void Alpha_Beta_Filter::init(const std::complex<double> &inputFirstElement);

    std::complex<double> Alpha_Beta_Filter::FiltrationElementwise(std::complex<double> &inputSignal);

    void Filtration(const std::vector<std::complex<double> > &inputSignal, std::vector<std::complex<double> > &outputSignal);
private:
    double Tau;
    double alpha;
    double beta;

    std::complex<double> xFiltered;
    std::complex<double> xFiltered_dot;
};

#endif //FILTER_ALPHA_BETA_FILTER_H
