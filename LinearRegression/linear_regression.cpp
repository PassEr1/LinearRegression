#include <iostream>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include<time.h>
#include <cstdint>
#include "data_sample.hpp"

double compute_hypothesis(int thetha_0, int thetha_1, int varient)
{
    return thetha_0 + thetha_1 * varient;
}

std::vector<DataSample> load_data_set()
{
    uint32_t DATA_SET_LENGTH = 5;
    std::vector<DataSample> data_set;
    data_set.reserve(DATA_SET_LENGTH);
    static const std::wstring NAME_OF_DATA_FILE = L"../data_set.txt";
    std::ifstream data_set_file(NAME_OF_DATA_FILE);
    double input, output;
    std::string line;
    while (std::getline(data_set_file, line))
    {
        std::cout << line << std::endl;
    }
  /*  while (data_set_file >> input >> output)
    {
        std::wcout << input << L" " << output << std::endl;
        data_set.emplace_back(input, output);
    }*/

    return data_set;
}

double cost_function(int thetha_0, int thetha_1, double input, double output)
{
    double diff = output - compute_hypothesis(thetha_0, thetha_1, input);
    static const int SQUARED_POW = 2;
    return std::pow(diff, SQUARED_POW);
}

double cost_function_direvative_respect_to_thetha_0(double thetha_0, double thetha_1, const std::vector<DataSample>& data_set)
{
    double sigma_results= 0;
    std::for_each(data_set.begin(), data_set.end(),
        [&](const DataSample& data_sample) {
            double hypothesis_output = compute_hypothesis(thetha_0, thetha_1, data_sample.get_input());
            sigma_results += hypothesis_output - data_sample.get_output();
        });

    double data_length = data_set.size();
    return sigma_results / data_length;
}

double cost_function_direvative_respect_to_thetha_1(double thetha_0, double thetha_1, const std::vector<DataSample>& data_set)
{
    double sigma_results = 0;
    std::for_each(data_set.begin(), data_set.end(),
        [&](const DataSample& data_sample) {
            double hypothesis_output = compute_hypothesis(thetha_0, thetha_1, data_sample.get_input());
            sigma_results += (hypothesis_output - data_sample.get_output()) * data_sample.get_input();
        });

    double data_length = data_set.size();
    return sigma_results / data_length;
}


double cost_function(double thetha_0, double thetha_1, const std::vector<DataSample>& data_set)
{
    double sigma_cost_function=0;
    std::for_each(data_set.begin(), data_set.end(),
        [&](const DataSample& data_sample) {
            sigma_cost_function += cost_function(
                thetha_0, 
                thetha_1, 
                data_sample.get_input(), 
                data_sample.get_output());
        });

    double data_length = data_set.size();
    //std::wcout << L"cost function is: " << sigma_cost_function / (2 * data_length) << std::endl;
    return sigma_cost_function / (2 * data_length);
}

void train_hypothesis(double& thetha_0, double& thetha_1, const std::vector<DataSample>& data_set)
{
    static const double TRAINING_ENDED = 0.6;
    double new_thetha_0 = thetha_0;
    double new_thetha_1 = thetha_1;

    while (cost_function(thetha_0, thetha_1, data_set) > TRAINING_ENDED)
    {
        static const double ALPHA = 0.001;
        
        new_thetha_0 = thetha_0 - ALPHA * cost_function_direvative_respect_to_thetha_0(
            thetha_0,
            thetha_1,
            data_set);
        new_thetha_1 = thetha_1 - ALPHA * cost_function_direvative_respect_to_thetha_1(
            thetha_0, 
            thetha_1, 
            data_set);
        thetha_0 = new_thetha_0;
        thetha_1 = new_thetha_1;
        std::cout << thetha_0 << " " << thetha_1 << std::endl;
    }
}

int main()
{
    std::vector<DataSample> data_set = load_data_set();
    srand(time(NULL));
    double thetha_0 = rand() % 5 ;
    double thetha_1 = rand() % 5;
    train_hypothesis(thetha_0, thetha_1, data_set);
    std::wcout << L"the trained hpyothesis is: y = " << thetha_0 << L" + " << thetha_1 << L"x" << std::endl;
}
