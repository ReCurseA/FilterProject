//
// Created by reuno on 02.10.2020.
//

#ifndef FILTER_FILTER_H
#define FILTER_FILTER_H

#include <vector>
#include <complex>
#include <algorithm>

class Filter {
public:
    Filter();
    ~Filter();

    virtual void Filtration(const std::vector<std::complex<double> > &inputSignal, std::vector<std::complex<double> > &outputSignal) {};

protected:
    std::vector<double> filterData;
};


#endif //FILTER_FILTER_H
