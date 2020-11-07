#pragma once
#include <vector>
#include <string>
#include "data_sample.hpp"
#include "data_set.hpp"
namespace LoadData
{
	std::vector<double> extract_features(const std::wstring& line, wchar_t delim);
	DataSetPtr load_data_set();
}
