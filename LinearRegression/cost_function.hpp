#pragma once
#include "data_sample.hpp"
#include "data_set.hpp"
#include "hypothesis.hpp"

class CostFunction final
{
public:
	explicit CostFunction(DataSetPtr data_set_ptr);

public:
	CostFunction() = delete;
	CostFunction(const CostFunction&) = default;
	CostFunction(CostFunction&&) = delete;
	CostFunction& operator=(const CostFunction&) = delete;
	CostFunction& operator=(CostFunction&&) = delete;

public:
	double compute(const std::shared_ptr<Hypothesis> hypothesis) const;
	double compute_derivative_in_respect_to_feature(const std::shared_ptr<Hypothesis> hypothesis, uint32_t feature_index) const;

private:
	const DataSetPtr _data_set_ptr;
};
