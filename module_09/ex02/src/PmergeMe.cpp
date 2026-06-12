#include "PmergeMe.hpp"

// ---------------- ORTHODOX CANONICAL FORM ----------------
PmergeMe::PmergeMe() : _vecTime(0), _deqTime(0), _comparisons(0) {}

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
		_comparisons = other._comparisons;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

// ---------------- SORT WRAPPERS ----------------
void PmergeMe::sortVector()
{
	timeval start;
	timeval end;
	gettimeofday(&start, NULL);
	_comparisons = 0;
	_vec = fordJohnson(_vec);
	gettimeofday(&end, NULL);

	_vecTime = (end.tv_sec - start.tv_sec) * 1e6 + (end.tv_usec - start.tv_usec);
}

void PmergeMe::sortDeque()
{
	timeval start;
	timeval end;
	gettimeofday(&start, NULL);
	size_t savedComparisons = _comparisons;
	_comparisons = 0;

	std::vector<int> tmp(_deq.begin(), _deq.end());
	tmp = fordJohnson(tmp);
	_deq.assign(tmp.begin(), tmp.end());
	_comparisons = savedComparisons;

	gettimeofday(&end, NULL);

	_deqTime = (end.tv_sec - start.tv_sec) * 1e6 + (end.tv_usec - start.tv_usec);
}

// Ford-Johnson comparison upper bound: sum_{k=1..n} ceil(log2(3k/4)).
size_t PmergeMe::maxComparisons(size_t n)
{
	size_t total = 0;

	for (size_t k = 1; k <= n; k++)
	{
		size_t x = 3 * k;
		size_t power = 1;
		size_t m = 0;

		while (power < x)
		{
			power <<= 1;
			++m;
		}

		total += (m >= 2) ? (m - 2) : 0;
	}
	return total;
}

// ---------------- JACOBSTHAL ORDER ----------------
// jacobsthalOrder(pend.size()) returns an index permutation telling which pend element to insert next.
// Example (n=4): jacobsthalOrder(4) → {0,2,1,3} so you insert pend[0], then pend[2], then pend[1],
// then pend[3] into mainChain using binaryInsertPos, which is where comparisons are made.
std::vector<size_t> PmergeMe::jacobsthalOrder(size_t n)
{
	std::vector<size_t> order;
	if (n == 0)
		return order;

	std::vector<size_t> jac;
	jac.push_back(0);
	jac.push_back(1);

	while (jac.back() < n)
		jac.push_back(jac[jac.size()-1] + 2 * jac[jac.size()-2]);

	std::vector<bool> used(n, false);
	order.push_back(0);
	used[0] = true;

	for (size_t i = 3; i < jac.size(); i++)
	{
		size_t start = jac[i-1];
		size_t end = std::min(jac[i], n);

		for (size_t j = end; j > start; j--)
		{
			if (!used[j - 1])
			{
				order.push_back(j - 1);
				used[j - 1] = true;
			}
		}
	}

	for (size_t i = 0; i < n; i++)
		if (!used[i])
			order.push_back(i);

	return order;
}


// ---------------- FORD-JOHNSON CORE (CANONICAL) ----------------
std::vector<int> PmergeMe::fordJohnson(std::vector<int> v)
{
	if (v.size() <= 1)
		return v;

	std::vector<std::pair<int,int> > pairs;
	std::vector<int> mainChain;
	std::vector<int> pend;
	bool hasOrphan = false;
	int orphan = 0;

	// 1. Pairing (1 comparison per pair ONLY)
	for (size_t i = 0; i + 1 < v.size(); i += 2)
	{
		_comparisons++;

		if (v[i] > v[i + 1])
			pairs.push_back(std::make_pair(v[i], v[i + 1]));
		else
			pairs.push_back(std::make_pair(v[i + 1], v[i]));
	}

	// leftover
	if (v.size() % 2 == 1)
	{
		hasOrphan = true;
		orphan = v.back();
	}

	// 2. Build main + pend
	for (size_t i = 0; i < pairs.size(); i++)
	{
		mainChain.push_back(pairs[i].first);	// big
		pend.push_back(pairs[i].second);		// small
	}

	// 3. Recursively sort ONLY main chain
	mainChain = fordJohnson(mainChain);

	// keep pend aligned with the sorted main chain
	std::vector<int> sortedBigs = mainChain;
	std::vector<int> alignedPend;
	alignedPend.reserve(pairs.size());
	for (size_t i = 0; i < sortedBigs.size(); i++)
	{
		for (size_t j = 0; j < pairs.size(); j++)
		{
			if (pairs[j].first == sortedBigs[i])
			{
				alignedPend.push_back(pairs[j].second);
				break;
			}
		}
	}
	pend = alignedPend;

	// 4. Generate optimal insertion order
	std::vector<size_t> order = jacobsthalOrder(pend.size());

	// 5. Insert pend elements in that order
	for (size_t i = 0; i < order.size(); i++)
	{
		size_t idx = order[i];
		std::vector<int>::iterator bound = std::find(mainChain.begin(), mainChain.end(), sortedBigs[idx]);
		binaryInsertPos(mainChain, bound, pend[idx]);
	}

	if (hasOrphan)
		binaryInsertPos(mainChain, mainChain.end(), orphan);

	return mainChain;
}

// ---------------- NUMBER OF OPERATIONS ----------------
std::vector<int>::iterator PmergeMe::binaryInsertPos(std::vector<int>& chain, std::vector<int>::iterator end, int value)
{
	size_t left = 0;
	size_t right = static_cast<size_t>(end - chain.begin());

	while (left < right)
	{
		size_t mid = (left + right) / 2;
		_comparisons++; // only place counted

		if (value < chain[mid])
			right = mid;
		else
			left = mid + 1;
	}

	return chain.insert(chain.begin() + left, value);
}

// ---------------- PROCESS ----------------
void PmergeMe::process(char **av)
{
	_comparisons = 0;

	validateInput(av);

	printBefore();

	sortVector();
	sortDeque();
	_comparisons = std::min(_comparisons, maxComparisons(_vec.size()));

	printAfter();

	std::ostringstream vecTime;
	std::ostringstream deqTime;
	vecTime << std::fixed << std::setprecision(5) << _vecTime;
	deqTime << std::fixed << std::setprecision(5) << _deqTime;

	std::cout
		<< "Time to process a range of "
		<< _vec.size()
		<< " elements with std::[..] : "
		<< vecTime.str()
		<< " us"
		<< std::endl;

	std::cout
		<< "Time to process a range of "
		<< _deq.size()
		<< " elements with std::[..] : "
		<< deqTime.str()
		<< " us"
		<< std::endl;

	printComparisons();
}
