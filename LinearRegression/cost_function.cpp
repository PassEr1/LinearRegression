#include <algorithm>
#include <math.h>
#include <iostream>
#include "cost_function.hpp"

CostFunction::CostFunction(DataSetPtr data_set_ptr)
:_data_set_ptr(data_set_ptr),
_log_cost_function(nullptr)
{}

double CostFunction::compute(const std::shared_ptr<Hypothesis> hypothesis) const
{
	double result = 0;
	std::for_each(_data_set_ptr->begin(), _data_set_ptr->end(),
		[&hypothesis, &result](const DataSample& data_sample) {
			double diff = hypothesis->compute_result(data_sample.get_input()) - data_sample.get_output();
			static const uint32_t SQARED = 2;
			result += pow(diff, SQARED);
		});

	static const uint32_t TO_HALF = 2;
	result = (result / _data_set_ptr->size()) / TO_HALF;
	if (_log_cost_function) { _log_cost_function(result); };
	return result;
}

double CostFunction::compute_derivative_in_respect_to_feature(const std::shared_ptr<Hypothesis> hypothesis, uint32_t feature_index) const
{
	double result = 0;
	std::for_each(_data_set_ptr->begin(), _data_set_ptr->end(),
		[&hypothesis, &result, &feature_index](const DataSample& data_sample) {
			double diff = hypothesis->compute_result(data_sample.get_input()) - data_sample.get_output();
			result += diff * data_sample.get_input()[feature_index];
		});

	result = result / _data_set_ptr->size();
	return result;
}

void CostFunction::set_log_cost_function(LogCostFunctionType func)
{
	_log_cost_function = func;
}

