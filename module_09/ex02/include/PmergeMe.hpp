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
		
		//vec algorithm
		void sortVector();
		//deque algorithm
		void sortDeque();

		//void binarySearch(); ????
		
		//Ford-Johnson vec
		std::vector<int>fordJohnsonVector(std::vector<int> input);
		//Ford-Johnson deque
		std::deque<int>fordJohnsonDeque(std::deque<int> input);

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		void run(int ac, char **av);

};

// The idea =

/* Will do the follow :) 
	->	INPUT
 
	->	PARSE

	->	PAIR ELEMENTS
	
	->	ORDER EACH PAIR (big, small)

	->	MAIN CHAIN = all bigs
	->	PEND       = all smalls

	->	SORT MAIN CHAIN

	->	INSERT PEND with binary search

	=	FINAL SORTED RESULT 
*/

#endif