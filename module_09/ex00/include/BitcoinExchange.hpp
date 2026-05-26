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
	std::map<std::string, double> _database; // automatically stored by date, allows fast lookup

	void trim(std::string &s) const; //removes spaces

	bool isValidDate(const std::string &date) const;
	bool isValidValue(const std::string &valueStr, double &value) const;
	
	std::map<std::string, double>::const_iterator // we need to return a reference to an element inside _database
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