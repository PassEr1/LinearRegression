#pragma once
#include <string>
#include <vector>
#include <memory>
#include "hypothesis_printer_iterator.hpp"

class HypothesisPrinter
{
public:
	explicit HypothesisPrinter(const std::vector<double>& thethas);

public:
	HypothesisPrinterConstIterator begin() const;
	HypothesisPrinterConstIterator end() const;

private:
	const std::vector<double> _thethas;
};


