#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	_database = other._database;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		_database = other._database;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{}

// removes spaces 
void BitcoinExchange::trim(std::string &s) const
{
	while (!s.empty() && (s[0] == ' ' || s[0] == '\t'))
		s.erase(0, 1);

	while (!s.empty() && (s[s.size() - 1] == ' ' || s[s.size() - 1] == '\t'))
		s.erase(s.size() - 1);
}

void BitcoinExchange::loadDatabase(const std::string& filename)
{
	std::ifstream file(filename.c_str());

	if (!file.is_open())
	{
		std::cerr << "Error: could not open database file." << std::endl;
		return;
	}

	std::string line;
	std::getline(file, line); // skip header: date,exchange_rate

	while (std::getline(file, line))
	{
		std::stringstream ss(line);

		std::string date;
		std::string rateStr;

		// split CSV line
		if (!std::getline(ss, date, ',') || !std::getline(ss, rateStr))
			continue;

		trim(date);
		trim(rateStr);

		// convert string -> double
		double rate = std::strtod(rateStr.c_str(), NULL);

		// store in map
		_database[date] = rate;
	}

	file.close();
}

bool BitcoinExchange::isValidValue(const std::string &valueStr, double &value) const
{
	char *end;

	value = std::strtod(valueStr.c_str(), &end);

	if (*end != '\0')
		return false;
	if (value < 0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return false;
	}
	if (value > 1000)
	{
		std::cerr << "Error: too large a number." << std::endl;
		return false;
	}
	return true;
}

bool BitcoinExchange::isValidDate(const std::string &date) const
{
	if (date.length() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;
	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (!isdigit(date[i]))
			return false;
	}
	return true;
}

std::map<std::string, double>::const_iterator
BitcoinExchange::getClosestDate(const std::string &date) const
{
	std::map<std::string, double>::const_iterator it = _database.lower_bound(date);

	if (it != _database.end() && it->first == date)
		return it;
	if (it == _database.begin())
		throw std::runtime_error("Error: no earlier date available");
	if (it == _database.end() || it->first != date)
		--it;
	
}

void BitcoinExchange::processInputFile(const std::string& filename)
{
	std::ifstream file(filename.c_str());

	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}
	std::string line;
    std::getline(file, line); // skip header

	while (std::getline(file, line))
	{
		std::stringstream ss(line);

		std::string date;
		std::string valueStr;

		if (!std::getline(ss, date, '|') ||
			!std::getline(ss, valueStr))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
			}

			trim(date);
			trim(valueStr);

			if (!isValidDate(date))
			{
				std::cerr << "Error: bad input => " << line << std::endl;
				continue;
			}

			double value;
			if (!isValidValue(valueStr, value))
				continue;

			try
			{
				std::map<std::string, double>::const_iterator it = getClosestDate(date);

				double result = value * it->second;

				std::cout << date << " => " << value
						<< " = " << result << std::endl;
			}
			catch (std::exception &e)
			{
				std::cerr << e.what() << std::endl;
			}
		}

	file.close();
}