#include "PmergeMe.hpp"

// ---------------- ORTHODOX CANONICAL FORM
PmergeMe::PmergeMe() : _vecTime(0), _deqTime(0) {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	*this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
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

PmergeMe::~PmergeMe() {}


// ============================================================
// INSERTION HELPERS (binary insertion using lower_bound)
// ============================================================

void PmergeMe::insertSorted(std::vector<int>& mainChain, int value)
{
	std::vector<int>::iterator pos =
		std::lower_bound(mainChain.begin(), mainChain.end(), value);
	mainChain.insert(pos, value);
}

void PmergeMe::insertSortedDeque(std::deque<int>& mainChain, int value)
{
	std::deque<int>::iterator pos =
		std::lower_bound(mainChain.begin(), mainChain.end(), value);
	mainChain.insert(pos, value);
}


// ============================================================
// PAIRING HELPERS (build (max, min) pairs)
// ============================================================

std::vector<std::pair<int,int> > PmergeMe::makePairsVector(const std::vector<int>& input)
{
	std::vector<std::pair<int,int> > pairs;

	for (size_t i = 0; i + 1 < input.size(); i += 2)
	{
		int a = input[i];
		int b = input[i + 1];

		// ensure first is always the larger value
		if (a < b)
			std::swap(a, b);

		pairs.push_back(std::make_pair(a, b));
	}
	return pairs;
}

std::deque<std::pair<int,int> > PmergeMe::makePairsDeque(const std::deque<int>& input)
{
	std::deque<std::pair<int,int> > pairs;

	for (size_t i = 0; i + 1 < input.size(); i += 2)
	{
		int a = input[i];
		int b = input[i + 1];

		if (a < b)
			std::swap(a, b);

		pairs.push_back(std::make_pair(a, b));
	}
	return pairs;
}


// ============================================================
// JACOBSTHAL SEQUENCE GENERATOR
// Used to optimize insertion order of "pend" elements
// ============================================================

static std::vector<size_t> generateJacobsthal(size_t n)
{
	std::vector<size_t> jacob;

	// J(0) = 0, J(1) = 1
	size_t prev = 0;
	size_t curr = 1;

	while (curr < n)
	{
		jacob.push_back(curr);
		size_t next = curr + 2 * prev;
		prev = curr;
		curr = next;
	}
	return jacob;
}


// ============================================================
// FORD–JOHNSON (VECTOR VERSION)
// ============================================================

std::vector<int> PmergeMe::fordJohnsonVector(const std::vector<int>& input)
{
	// ---------------- BASE CASE
	if (input.size() <= 1)
		return input;

	// ---------------- STEP 1: PAIR ELEMENTS
	std::vector<std::pair<int,int> > pairs;
	std::vector<int> unpaired;

	for (size_t i = 0; i < input.size(); i += 2)
	{
		if (i + 1 < input.size())
		{
			int a = input[i];
			int b = input[i + 1];

			// a = max, b = min
			if (a < b)
				std::swap(a, b);

			pairs.push_back(std::make_pair(a, b));
		}
		else
		{
			// odd element
			unpaired.push_back(input[i]);
		}
	}

	// ---------------- STEP 2: BUILD MAIN + PEND CHAINS
	std::vector<int> mainChain;
	std::vector<int> pend;

	for (size_t i = 0; i < pairs.size(); i++)
	{
		mainChain.push_back(pairs[i].first);   // larger elements
		pend.push_back(pairs[i].second);       // smaller elements
	}

	// ---------------- STEP 3: RECURSIVELY SORT MAIN CHAIN
	mainChain = fordJohnsonVector(mainChain);

	// ---------------- STEP 4: BUILD INSERTION ORDER (JACOBSTHAL)
	std::vector<size_t> order;
	std::vector<bool> used(pend.size(), false);

	std::vector<size_t> jacob = generateJacobsthal(pend.size());

	// insert jacobsthal indices first
	for (size_t i = 0; i < jacob.size(); i++)
	{
		size_t idx = jacob[i];

		if (idx == 0 || idx > pend.size())
			continue;

		if (!used[idx - 1])
		{
			order.push_back(idx - 1);
			used[idx - 1] = true;
		}
	}

	// insert remaining indices in order
	for (size_t i = 0; i < pend.size(); i++)
	{
		if (!used[i])
			order.push_back(i);
	}

	// ---------------- STEP 5: INSERT PEND ELEMENTS
	// insertion is done in optimized Jacobsthal order
	for (size_t i = 0; i < order.size(); i++)
	{
		insertSorted(mainChain, pend[order[i]]);
	}

	// ---------------- STEP 6: INSERT ODD ELEMENTS
	for (size_t i = 0; i < unpaired.size(); i++)
	{
		insertSorted(mainChain, unpaired[i]);
	}

	return mainChain;
}


// ============================================================
// FORD–JOHNSON (DEQUE VERSION)
// SAME LOGIC AS VECTOR FOR CONSISTENCY
// ============================================================

std::deque<int> PmergeMe::fordJohnsonDeque(const std::deque<int>& input)
{
	if (input.size() <= 1)
		return input;

	std::deque<std::pair<int,int> > pairs;
	std::deque<int> unpaired;

	// pairing
	for (size_t i = 0; i < input.size(); i += 2)
	{
		if (i + 1 < input.size())
		{
			int a = input[i];
			int b = input[i + 1];

			if (a < b)
				std::swap(a, b);

			pairs.push_back(std::make_pair(a, b));
		}
		else
		{
			unpaired.push_back(input[i]);
		}
	}

	// main + pend
	std::deque<int> mainChain;
	std::deque<int> pend;

	for (size_t i = 0; i < pairs.size(); i++)
	{
		mainChain.push_back(pairs[i].first);
		pend.push_back(pairs[i].second);
	}

	// recursive sort
	mainChain = fordJohnsonDeque(mainChain);

	// Jacobsthal order
	std::vector<size_t> order;
	std::vector<bool> used(pend.size(), false);
	std::vector<size_t> jacob = generateJacobsthal(pend.size());

	for (size_t i = 0; i < jacob.size(); i++)
	{
		size_t idx = jacob[i];

		if (idx == 0 || idx > pend.size())
			continue;

		if (!used[idx - 1])
		{
			order.push_back(idx - 1);
			used[idx - 1] = true;
		}
	}

	for (size_t i = 0; i < pend.size(); i++)
	{
		if (!used[i])
			order.push_back(i);
	}

	// insertion
	for (size_t i = 0; i < order.size(); i++)
		insertSortedDeque(mainChain, pend[order[i]]);

	for (size_t i = 0; i < unpaired.size(); i++)
		insertSortedDeque(mainChain, unpaired[i]);

	return mainChain;
}


// ============================================================
// SORT + TIMING
// ============================================================

void PmergeMe::sortVector()
{
	clock_t start = clock();
	_vec = fordJohnsonVector(_vec);
	clock_t end = clock();

	_vecTime = (double(end - start) / CLOCKS_PER_SEC) * 1000000;
}

void PmergeMe::sortDeque()
{
	clock_t start = clock();
	_deq = fordJohnsonDeque(_deq);
	clock_t end = clock();

	_deqTime = (double(end - start) / CLOCKS_PER_SEC) * 1000000;
}


// ============================================================
// INPUT PARSING (SAFE VERSION)
// ============================================================

void PmergeMe::parseInput(int ac, char **av)
{
	for (int i = 1; i < ac; i++)
	{
		std::string str(av[i]);

		if (str.empty())
			throw std::runtime_error("Error");

		char *end;
		long value = std::strtol(str.c_str(), &end, 10);

		// invalid characters check
		if (*end != '\0')
			throw std::runtime_error("Error");

		// overflow / negative check
		if (value < 0 || value > std::numeric_limits<int>::max())
			throw std::runtime_error("Error");

		_vec.push_back((int)value);
		_deq.push_back((int)value);
	}
}


// ============================================================
// RUN
// ============================================================

void PmergeMe::run(int ac, char **av)
{
	parseInput(ac, av);

	std::vector<int> before = _vec;

	sortVector();
	sortDeque();

	std::cout << "Before: ";
	for (size_t i = 0; i < before.size(); i++)
		std::cout << before[i] << " ";
	std::cout << std::endl;

	std::cout << "After:  ";
	for (size_t i = 0; i < _vec.size(); i++)
		std::cout << _vec[i] << " ";
	std::cout << std::endl;

	std::cout << "Time to process " << _vec.size()
			  << " elements with std::vector : "
			  << _vecTime << " us" << std::endl;

	std::cout << "Time to process " << _deq.size()
			  << " elements with std::deque : "
			  << _deqTime << " us" << std::endl;
}