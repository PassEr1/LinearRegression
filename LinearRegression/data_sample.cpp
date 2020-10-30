#include "data_sample.hpp"

DataSample::DataSample(double input, double output)
:_input(input),
_output(output)
{}

double DataSample::get_input() const
{
	return _input;
}

double DataSample::get_output() const
{
	return _output;
}
