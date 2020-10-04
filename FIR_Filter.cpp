//
// Created by reuno on 02.10.2020.
//

#include "FIR_Filter.h"


#include <iostream>

FIR_Filter::FIR_Filter(const std::string &FileName)
{
    NameOfFile = FileName;
    getFIR_Filter();
}

void FIR_Filter::Filtration(const std::vector<std::complex<double>> &inputSignal, std::vector<std::complex<double>> &outputSignal) {
    const int zero = 0;
    int convSize = inputSignal.size() + filterData.size() - 1;
    outputSignal.resize(convSize, std::complex<double> (0,0));
    for (int n = 0; n < convSize; n++) {
        int start = std::max(zero, (n + 1 - static_cast<int>(filterData.size())));
        int end = std::min(n, static_cast<int>(inputSignal.size() - 1));
        for (int m = start; m <= end; m++) {
            outputSignal[n] += inputSignal[m] * filterData[n - m];
        }
    }
}

void FIR_Filter::getFIR_Filter()
{
    std::fstream input(NameOfFile.c_str(), std::ios::in | std::ios::binary);

    if (input.is_open())
    {
        while (!input.eof())
        {
            double value;
            input.read((char *) &value, sizeof(double));
            filterData.push_back(value);
        }
    }
    else
    {
       std::cout << "Filter file isn't open" << std::endl;
    }
    input.close();
}