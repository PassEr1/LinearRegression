#pragma once
#include <vector>
#include <string>

class Hypothesis final 
{
public:
	Hypothesis(const std::vector<double> thethas);

public:
	Hypothesis()							 = delete;
	Hypothesis(const Hypothesis&)			 = default;
	Hypothesis(Hypothesis&&)				 = delete;
	Hypothesis& operator=(const Hypothesis&) = delete;
	Hypothesis& operator=(Hypothesis&&)		 = delete;

public:
	double compute_result(std::vector<double> inputs) const;
	void add_to_theth_i(uint32_t thetha_index, double to_add);
	uint32_t num_of_thethas() const;
	std::wstring to_string() const;
private:
	std::vector<double> _thethas;
};
