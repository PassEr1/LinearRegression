#pragma once
#include <vector>

class DataSample 
{
public:
	DataSample(double input, double output);

public:
	DataSample(DataSample&&) = default;
	DataSample& operator=(DataSample&&) = default;

public:
	DataSample(const DataSample&) = delete;
	DataSample operator=(const DataSample&) = delete;

public:
	double get_input() const;
	double get_output() const;

private: 
	double _input;
	double _output;
};
