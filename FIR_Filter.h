//
// Created by reuno on 02.10.2020.
//

#ifndef FILTER_FIR_FILTER_H
#define FILTER_FIR_FILTER_H

#include "Filter.h"

#include <complex>
#include <string>
#include <fstream>

class FIR_Filter : public Filter
{
public:
    FIR_Filter(const std::string &FileName);

    void Filtration(const std::vector<std::complex<double> > &inputSignal, std::vector<std::complex<double> > &outputSignal);
private:
    void getFIR_Filter();

    std::string NameOfFile;
};


#endif //FILTER_FIR_FILTER_H
