#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include <vector>
#include <complex>

#include "FIR_Filter.h"
#include "Alpha_Beta_Filter.h"

// function for writing results in binary files
void WriteComplexSignalInFile(std::vector<std::complex<double> > &signal, const std::string &NameFile){
    std::ofstream f1(NameFile, std::ios::out | std::ios::binary);
    if (f1.is_open())
    {
        for (int j = 0; j < signal.size(); j++)
        {
            double i = signal[j].real();
            double q = signal[j].imag();

            f1.write((char *) &i, sizeof(double));
            f1.write((char *) &q, sizeof(double));
        }
    }
    else
    {
        std::cout << "Signal file isn't open" << std::endl;
    }
    f1.close();
}

// generating normal distribution
void GenerateComplexSignal(std::vector<std::complex<double> > & signal, int size)
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator (seed);
    std::normal_distribution<double> distribution(0.0,1.0);

    for (int j = 0; j < size; j++)
    {
        double i = distribution(generator);
        double q = distribution(generator);
        std::complex<double> iq(i,q);

        signal.push_back(iq);
    }
}

int main() {
    std::vector<std::complex<double> > signal;
    GenerateComplexSignal(signal, 50);

    FIR_Filter FIR_1 = FIR_Filter("FIR_Filter_lowpass_data.bin"); // specify your file path

    std::vector<std::complex<double> > resultFir;
    FIR_1.Filtration(signal, resultFir);
    WriteComplexSignalInFile(resultFir, "FIR_Filter_result.bin"); // writing result to file

    Alpha_Beta_Filter AB_1 = Alpha_Beta_Filter();
    AB_1.setTau(0.9); // setting Tau parameter
    AB_1.setAlphaBeta();

    AB_1.init(signal[0]); // first xFiltered and xFiltered_dot

    std::vector<std::complex<double> > resultAlphaBeta;
    /*
    AB_1.Filtration(signal, resultAlphaBeta);
    WriteComplexSignalInFile(resultAlphaBeta, "AlphaBeta_Filter_result.bin"); // writing result to file
    */
    resultAlphaBeta.resize(signal.size(), std::complex<double> (0,0));
    for (int j = 0; j < signal.size(); j++){
        resultAlphaBeta[j] = AB_1.FiltrationElementwise(signal[j]);
    }
    WriteComplexSignalInFile(resultAlphaBeta, "AlphaBeta_Filter_result.bin"); // writing result to file
    return 0;
}

