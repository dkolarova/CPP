#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <ctime>
#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <cctype>

class PmergeMe
{
	private:
		//containers
		std::vector<int> _vec;
		std::deque<int> _deq;

		//parsing
		void parseInput(int ac, char **av);
		
		//main drivers
		void sortVector();
		void sortDeque();
		
		//Ford-Johnson core
		std::vector<int> fordJohnsonVector(const std::vector<int>& input);
		std::deque<int> fordJohnsonDeque(const std::deque<int>& input);
		// pairing
    	std::vector<std::pair<int,int> > makePairsVector(const std::vector<int>& input);
    	std::deque<std::pair<int,int> > makePairsDeque(const std::deque<int>& input);

		// insertion helper (using STL)
		void insertSorted(std::vector<int>& mainChain, int value);
		void insertSortedDeque(std::deque<int>& mainChain, int value);

		// time
		double _vecTime;
		double _deqTime;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		void run(int ac, char **av);

};

#endif
