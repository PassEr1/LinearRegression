#include<algorithm>
#include <functional>
#include <numeric>
#include <string>
#include "hypothesis.hpp"
#include "exceptions.hpp"
#include "hypothesis_printer.hpp"

uint32_t Hypothesis::num_of_thethas() const
{
	return _thethas.size();
}

std::wstring Hypothesis::to_string() const
{
	HypothesisPrinter printer(_thethas);
	std::wstring output = L"F(x) = ";
	for (auto thetha_i : printer)
	{
		output.append(thetha_i);
	}
	return output;
}

Hypothesis::Hypothesis(const std::vector<double> thethas)
:_thethas(thethas)
{}

double Hypothesis::compute_result(std::vector<double> inputs) const
{
	if (inputs.size() != _thethas.size())
	{
		throw MyException(ErrorCode::NUMBER_OF_INPUTS_TO_HYPOTHESIS_IS_WRONG);
	}
	double result = 0;
	for (size_t i = 0; i < inputs.size(); i++)
	{
		result += inputs[i] * _thethas[i];
	}

	return result;
}
void Hypothesis::add_to_theth_i(uint32_t thetha_index, double to_add)
{
	_thethas[thetha_index] += to_add;
}

