#include "hypothesis_printer.hpp"
#include "hypothesis_printer_iterator.hpp"

HypothesisPrinter::HypothesisPrinter(const std::vector<double>& thethas)
:_thethas(thethas){}



HypothesisPrinterConstIterator HypothesisPrinter::begin() const
{
	return HypothesisPrinterConstIterator(_thethas.begin());
}

HypothesisPrinterConstIterator HypothesisPrinter::end() const
{
	return HypothesisPrinterConstIterator(_thethas.end());
}

