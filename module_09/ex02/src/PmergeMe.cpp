#include "PmergeMe.hpp"

// ORTX-CANONICAL FORM
PmergeMe::PmergeMe() : _vecTime(0), _deqTime(0) {}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	*this = other;
}
PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		_vec = other._vec;
		_deq = other._deq;
		_vecTime = other._vecTime;
		_deqTime = other._deqTime;
	}
	return *this;
}

PmergeMe::~PmergeMe(){}

// VALIDATION (no negatives, no duplicates, only digits)
void PmergeMe::validateInput(char **av)
{
	std::set<int> seen;

	for (int i = 1; av[i]; i++)
	{
		std::string s(av[i]);

		if (s.empty())
			throw std::runtime_error("Error");

		for (size_t j = 0; j < s.size(); j++)
		{
			if (!std::isdigit(s[j]))
				throw std::runtime_error("Error");
		}

		long value = std::strtol(av[i], NULL, 10);

		if (value < 0 || value > INT_MAX)
			throw std::runtime_error("Error");

		if (seen.count(value))
			throw std::runtime_error("Error");

		seen.insert(value);

		_vec.push_back((int)value);
		_deq.push_back((int)value);
	}
}

//PROCESS
void PmergeMe::process(char **av)
{
	validateInput(av);

	printBefore();

	sortVector();
	sortDeque();

	printAfter();

	std::cout
		<< "Time to process a range of "
		<< _vec.size()
		<< " elements with std::vector : "
		<< _vecTime
		<< " us"
		<< std::endl;

	std::cout
		<< "Time to process a range of "
		<< _deq.size()
		<< " elements with std::deque : "
		<< _deqTime
		<< " us"
		<< std::endl;
}

//PRINTING
void PmergeMe::printBefore() const
{
	std::cout << "Before: ";

	for (size_t i = 0; i < _vec.size(); i++)
		std::cout << _vec[i] << " ";

	std::cout << std::endl;
}

void PmergeMe::printAfter() const
{
	std::cout << "After: ";

	for (size_t i = 0; i < _vec.size(); i++)
		std::cout << _vec[i] << " ";

	std::cout << std::endl;
}

// VECTOR SORT WRAPPER
void PmergeMe::sortVector()
{
	clock_t start = clock();

	_vec = fordJohnson(_vec);

	clock_t end = clock();

	_vecTime = (double)(end - start) / CLOCKS_PER_SEC * 1e6;
}

// DEQUE SORT WRAPPER
void PmergeMe::sortDeque()
{
	clock_t start = clock();

	std::vector<int> tmp(_deq.begin(), _deq.end());
	tmp = fordJohnson(tmp);
	_deq.assign(tmp.begin(), tmp.end());

	clock_t end = clock();

	_deqTime = (double)(end - start) / CLOCKS_PER_SEC * 1e6;
}

//FORDJOHNSON CORE
std::vector<int> PmergeMe::fordJohnson(std::vector<int> v)
{
	if (v.size() <= 1)
		return v;

	struct Pair
	{
		int big;
		int small;
	};

	std::vector<Pair> pairs;
	std::vector<int> mainChain;
	std::vector<int> pend;

	//1.Pairing
	 for (size_t i = 0; i + 1 < v.size(); i += 2)
    {
		if (v[i] > v[i + 1])
			pairs.push_back((Pair){v[i], v[i + 1]});
		else
			pairs.push_back((Pair){v[i + 1], v[i]});
	}

	//leftover
	if (v.size() % 2 == 1)
		pend.push_back(v.back());

	//2. split main/pend
	for (size_t i = 0; i < pairs.size(); i++)
	{
		mainChain.push_back(pairs[i].big);
		pend.push_back(pairs[i].small);
	}

	//3.recursively sort main chain
	mainChain = fordJohnson(mainChain);

	//4. insert pend using binary search
	for (size_t i = 0; i < pend.size(); i++)
	{
		std::vector<int>::iterator pos =
			std::lower_bound(mainChain.begin(), mainChain.end(), pend[i]);

		mainChain.insert(pos, pend[i]);
	}
	return mainChain;
}

// missing:
// Jacobsthal insertion order (optimization step)
// comparison counter (for learning/debugging)
// iterative Ford–Johnson (instead of recursion)