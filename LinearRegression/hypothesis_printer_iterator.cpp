#include "hypothesis_printer_iterator.hpp"

HypothesisPrinterConstIterator::HypothesisPrinterConstIterator(std::vector<double>::const_iterator inner_iter)
	:_iter(inner_iter)
{}

void HypothesisPrinterConstIterator::operator++()
{
	_iter++;
}

std::wstring HypothesisPrinterConstIterator::operator*() const
{
	
	static const wchar_t THETHA = L'T';
	static const wchar_t SPACE = L' ';
	return std::to_wstring(*_iter) + THETHA + SPACE;
}

bool HypothesisPrinterConstIterator::operator!=(const HypothesisPrinterConstIterator & right) const
{
	return _iter != right._iter;
}
