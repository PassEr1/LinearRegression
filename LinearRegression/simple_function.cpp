#include <math.h>
#include "simple_function.hpp"

SimpleFunction::SimpleFunction(uint32_t coefficient, uint32_t exponent)
:_exponent(exponent),
_coefficient(coefficient)
{}

uint64_t SimpleFunction::operator()(uint32_t varient) const
{
	return pow((_coefficient * varient), _exponent);
}

void SimpleFunction::update_coefficient(uint32_t coefficient)
{
	_coefficient = coefficient;
}
