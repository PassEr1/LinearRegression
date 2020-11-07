#pragma once
#include <memory>
#include "data_sample.hpp"

using DataSet = const std::vector<DataSample>;
using DataSetPtr = std::shared_ptr<DataSet>;
