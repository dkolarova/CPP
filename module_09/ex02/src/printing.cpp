#include "PmergeMe.hpp"

// ---------------- PRINT ----------------
static void printFull(const std::vector<int>& values)
{
	for (size_t i = 0; i < values.size(); i++)
	{
		std::cout << values[i];
		if (i + 1 < values.size())
			std::cout << " ";
	}
}
//for tester (no need)
static void printPreview(const std::vector<int>& values)
{
	const size_t previewSize = 5;
	const size_t previewThreshold = 20;

	if (values.size() <= previewThreshold)
	{
		printFull(values);
		return;
	}

	for (size_t i = 0; i < previewSize; i++)
	{
		std::cout << values[i];
		if (i + 1 < previewSize)
			std::cout << " ";
	}
	std::cout << " [...]";
}

// for tester (need: printFull(_vec))
void PmergeMe::printBefore() const
{
	std::cout << "Before: ";
	printPreview(_vec);
	std::cout << std::endl;
}

// for tester (need: printFull(_vec))
void PmergeMe::printAfter() const
{
	std::cout << "After: ";
	printPreview(_vec);
	std::cout << std::endl;
}

//----------- 	DEBUG "PRINT COMPARISIONS" ---------
void PmergeMe::printComparisons() const
{
	#if NUMBER_COMPARISIONS
	std::cout << "Number of comparisons: "
			<< _comparisons
			<< std::endl;
	#endif
}	

//for tester (need)
// void PmergeMe::printComparisons() const
// {
// 	std::cout << "Number of comparisons: " << _comparisons << std::endl;
// }