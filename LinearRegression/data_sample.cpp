#include <algorithm>
#include "data_sample.hpp"


DataSample::DataSample(const std::vector<double> features)
{
	load_input_features(features);
	load_output_features(features);	
}

std::vector<double> DataSample::get_input() const
{
	return _features;
}

double DataSample::get_output() const
{
	return _output;
}

void DataSample::load_input_features(const std::vector<double>& features)
{
	static const double CONVENTION_FIRST_INPUT_IS_1 = 1.0;
	_features.push_back(CONVENTION_FIRST_INPUT_IS_1);
	static const double LAST_OUTPUT_FEATURE = 1;
	_features.insert(_features.end(), features.begin(), features.end() - LAST_OUTPUT_FEATURE);
}

void DataSample::load_output_features(const std::vector<double>& features)
{
	_output = *(features.end() - 1);
}