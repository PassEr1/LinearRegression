#pragma once
#include <vector>
#include <string>

class HypothesisPrinterConstIterator final
{
public:
	HypothesisPrinterConstIterator(std::vector<double>::const_iterator inner_iter);

public:
	void operator++();
	std::wstring operator*() const;
	bool operator!=(const HypothesisPrinterConstIterator& right)const;


private:
	std::vector<double>::const_iterator _iter;
};
