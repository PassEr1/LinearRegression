#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include<time.h>
#include <cstdint>
#include <sstream>
#include "data_sample.hpp"
#include "load_data.hpp"
#include "exceptions.hpp"
#include "hypothesis.hpp"
#include "cost_function.hpp"


std::vector<double> apply_gradient_decent_on_thethas(const std::shared_ptr<Hypothesis> hypothesis,
    const std::shared_ptr<CostFunction> const_function, 
    double alpha)
{
    std::vector<double> new_thetthas;
    new_thetthas.reserve(hypothesis->num_of_thethas());
    for (size_t feature_index = 0; feature_index < new_thetthas.capacity(); feature_index++)
    {
        new_thetthas.emplace_back(-alpha * const_function->compute_derivative_in_respect_to_feature(hypothesis, feature_index));
    }

    return new_thetthas;
}

void train_hypothesis(std::shared_ptr<Hypothesis> hypothesis, DataSetPtr data_set)
{
    static const double TRAINING_ENDED = 0.5;
    CostFunction cost_function(data_set);

    static const std::wstring COST_FUNCTION_LOG_NAME = L"../cost_function.txt";
    std::wofstream log_file(COST_FUNCTION_LOG_NAME);
    auto write_to_file = [&log_file](double measure) {
        static const uint32_t PRECISION = 12;
        log_file.precision(PRECISION);
        log_file << measure << std::endl;
    };

    cost_function.set_log_cost_function(write_to_file);

    while (cost_function.compute(hypothesis) > TRAINING_ENDED)
    {
              
        static const double ALPHA = 0.00001;
        std::vector<double> new_thethas_to_update_in_hypothesis = apply_gradient_decent_on_thethas(
            hypothesis,
            std::make_shared<CostFunction>(cost_function),
            ALPHA);
        for (size_t thetha_i = 0; thetha_i < hypothesis->num_of_thethas(); thetha_i++)
        {
            hypothesis->add_to_theth_i(thetha_i, new_thethas_to_update_in_hypothesis[thetha_i]);
        }
    }
}


int main()
{
    try
    {
        DataSetPtr data_set = LoadData::load_data_set();

        srand(time_t(NULL));
        double thetha_0 = rand() % 5;
        double thetha_1 = rand() % 5;
        Hypothesis hypothesis_ax_c({ thetha_0, thetha_1 });
        std::shared_ptr<Hypothesis> shared_hypothesis= std::make_shared<Hypothesis>(hypothesis_ax_c);
        train_hypothesis(shared_hypothesis, data_set);
        
        std::wcout << L"the trained hpyothesis is: y = " << shared_hypothesis->to_string() << std::endl;
    }
    catch (MyException & e)
    {
        std::wcout << L"An error accoured. The error code is:"  << e.get_error_code() << std::endl;
    }
    catch (std::ios_base::failure& e)
    {
        std::wcout << L"An error accoured while attempted to read data set file. " << e.what() <<std::endl;        
    }
    catch (std::exception& e)
    {
        std::wcout << L"An unknown error accoured " << e.what() << std::endl;
    }

}
