#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <stdexcept>
#include <set>
#include <climits>
#include <cctype>

class PmergeMe
{
	private:
		std::vector<int> _vec;
		std::deque<int>  _deq;

		double _vecTime;
		double _deqTime;

		struct Pair
		{
			int big;
			int small;
		};

		void validateInput(char **av);

		void sortVector();
		void sortDeque();

		size_t maxComparisons(size_t n);
		std::vector<size_t> jacobsthalOrder(size_t n);
		std::vector<int> fordJohnson(std::vector<int> v);
		
		size_t _comparisons;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		void process(char **av);

		void printBefore() const;
		void printAfter() const;

		std::vector<int>::iterator binaryInsertPos(std::vector<int>& chain, std::vector<int>::iterator end, int value);
};

#endif