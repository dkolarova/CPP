#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <iostream>

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
		std::vector<int>fordJohnsonVector(std::vector<int> input);
		std::deque<int>fordJohnsonDeque(std::deque<int> input);

		// pairing
		std::vector<std::pair<int,int>> makePairsVector(std::vector<int>& input);
		std::deque<std::pair<int,int>> makePairsDeque(std::deque<int>& input);

		// insertion helper (using STL)
		void insertSorted(std::vector<int>& mainChain, int value);


	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		void run(int ac, char **av);

};

#endif
