#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <cstdlib>

class BitcoinExchange
{
	private:
	std::map<std::string, double> _database;

	void trim(std::string &s) const;

	bool isValidDate(const std::string &date) const;
	bool isValidValue(const std::string &valueStr, double &value) const;
	
	std::map<std::string, double>::const_iterator
	getClosestDate(const std::string &date) const;

	public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange();

	void loadDatabase(const std::string& filename);
	void processInputFile(const std::string& filename);
};

#endif


/* 
Steps:
parse
validate date
validate value
find rate via map
multiply
print
*/