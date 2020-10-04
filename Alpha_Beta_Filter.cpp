//
// Created by reuno on 03.10.2020.
//

#include "Alpha_Beta_Filter.h"

#include <iostream>

Alpha_Beta_Filter::Alpha_Beta_Filter() {}

Alpha_Beta_Filter::~Alpha_Beta_Filter() {}

void Alpha_Beta_Filter::setTau(double T){
    Tau = T;
}

double Alpha_Beta_Filter::getTau() {
    return Tau;
}

void Alpha_Beta_Filter::Filtration(const std::vector<std::complex<double>> &inputSignal, std::vector<std::complex<double>> &outputSignal)
{
    alpha = pow(1./2, Tau);
    beta = 8 - 4 * alpha - 8 * sqrt(1 - alpha);

    std::complex<double> xFiltered = inputSignal[0];
    std::complex<double> xFiltered_dot = 0;

    outputSignal.resize(inputSignal.size(), std::complex<double> (0,0));

    std::vector<std::complex<double> > forecast;
    forecast.resize(inputSignal.size(), std::complex<double> (0,0));
    std::vector<std::complex<double> > err;
    err.resize(inputSignal.size(), std::complex<double> (0,0));

    for (int j = 0; j < inputSignal.size(); j++) {
        forecast[j] = xFiltered + xFiltered_dot;
        err[j] = inputSignal[j] - forecast[j];
        xFiltered = forecast[j] + alpha * err[j];
        xFiltered_dot = xFiltered_dot + beta * err[j];

        outputSignal[j] = xFiltered;
    }
}