#pragma once
#include <cstdint>

class SimpleFunction final
{
public:
	explicit SimpleFunction(uint32_t coefficient, uint32_t exponent);

public:
	uint64_t operator()(uint32_t varient) const;
public:
	void update_coefficient(uint32_t coefficient);

public:
	SimpleFunction(const SimpleFunction&) = delete;
	SimpleFunction(SimpleFunction&&) = delete;
	SimpleFunction operator=(const SimpleFunction&) = delete;
	SimpleFunction&& operator=(SimpleFunction&&) = delete;

private:
	uint32_t _coefficient;
	const uint32_t _exponent;
};
