#include <BitcoinExchange.hpp>

// ---------------- ORTX-CANONICAL FORM ----------------

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	_database = other._database;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		_database = other._database;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

// ---------------- SPACES ----------------

void BitcoinExchange::trim(std::string &s) const
{
	while (!s.empty() && std::isspace(static_cast<unsigned char>(s[0])))
		s.erase(0, 1);

	while (!s.empty() && std::isspace(static_cast<unsigned char>(s[s.size() - 1])))
		s.erase(s.size() - 1);
}

// ---------------- LOAD DB ----------------

void BitcoinExchange::loadDatabase(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open database file." << std::endl;
		return;
	}

	std::string line;
	std::getline(file, line); // skip header

	while (std::getline(file, line))
	{
		std::stringstream ss(line);

		std::string date;
		std::string rateStr;

		if (!std::getline(ss, date, ',') || !std::getline(ss, rateStr))
			continue;

		trim(date);
		trim(rateStr);

		double rate = std::strtod(rateStr.c_str(), NULL);
		_database[date] = rate;
	}
}

// ---------------- VALUE VALIDATION ----------------

bool BitcoinExchange::isValidValue(const std::string &valueStr, double &value) const
{
	char *end;

	value = std::strtod(valueStr.c_str(), &end);

	if (*end != '\0')
		return false;

	return true;
}

// ---------------- DATE VALIDATION ----------------

bool BitcoinExchange::isValidDate(const std::string &date) const
{
	if (date.size() != 10)
		return false;

	if (date[4] != '-' || date[7] != '-')
		return false;

	for (size_t i = 0; i < date.size(); i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(static_cast<unsigned char>(date[i])))
			return false;
	}

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (month < 1 || month > 12)
		return false;

	int daysInMonth[] = {
		31, 28, 31, 30,
		31, 30, 31, 31,
		30, 31, 30, 31
	};

	// correct leap year
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		daysInMonth[1] = 29;

	if (day < 1 || day > daysInMonth[month - 1])
		return false;

	return true;
}

// ---------------- LOWER BOUND LOGIC ----------------
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

	return it;
}

// ---------------- INPUT PROCESSING ----------------

void BitcoinExchange::processInputFile(const std::string &filename)
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
		if (line.empty())
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::stringstream ss(line);

		std::string date;
		std::string valueStr;

		if (!std::getline(ss, date, '|') || !std::getline(ss, valueStr))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		trim(date);
		trim(valueStr);

		if (date.empty() || valueStr.empty())
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		if (!isValidDate(date))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		double value;
		if (!isValidValue(valueStr, value))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		if (value < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}

		if (value > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}

		try
		{
			std::map<std::string, double>::const_iterator it =
				getClosestDate(date);

			double result = value * it->second;

			std::cout	<< date 
						<< " => "
						<< value
						<< " = "
						<< result
						<< std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}
