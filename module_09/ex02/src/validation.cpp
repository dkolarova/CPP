#include "PmergeMe.hpp"

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
			if (!std::isdigit(static_cast<unsigned char>(s[j])))
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
