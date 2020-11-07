#pragma once
#include <vector>

class DataSample 
{
public:
	DataSample(const std::vector<double> features);

public:
	DataSample(DataSample&&) = default;
	DataSample& operator=(DataSample&&) = default;

public:
	DataSample(const DataSample&) = default;
	DataSample operator=(const DataSample&) = delete;

public:
	std::vector<double> get_input() const;
	double get_output() const;

private:
	void load_input_features(const std::vector<double>& features);
	void load_output_features(const std::vector<double>& features);

private: 
	std::vector<double> _features;
	double _output;
};
