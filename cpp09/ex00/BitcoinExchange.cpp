#include "BitcoinExchange.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cctype>

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
	: _rates(other._rates)
{
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
		_rates = other._rates;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

bool BitcoinExchange::validDate(const std::string& date) const
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	for (size_t i = 0; i < date.size(); ++i)
	{
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(static_cast<unsigned char>(date[i])))
			return false;
	}

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (month < 1 || month > 12 || day < 1)
		return false;

	int days[] = {
		31, 28, 31, 30, 31, 30,
		31, 31, 30, 31, 30, 31
	};

	if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
		days[1] = 29;

	return day <= days[month - 1];
}

bool BitcoinExchange::validValue(const std::string& text, double& value) const
{
	char* end = NULL;

	value = std::strtod(text.c_str(), &end);

	if (text.empty() || *end != '\0')
		return false;

	if (value < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return false;
	}

	if (value > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return false;
	}

	return true;
}

std::string BitcoinExchange::trim(const std::string& text) const
{
	size_t begin = 0;
	size_t end = text.size();

	while (begin < end &&
		   std::isspace(static_cast<unsigned char>(text[begin])))
		++begin;

	while (end > begin &&
		   std::isspace(static_cast<unsigned char>(text[end - 1])))
		--end;

	return text.substr(begin, end - begin);
}

bool BitcoinExchange::readDatabase(const std::string& filename)
{
	std::ifstream file(filename.c_str());

	if (!file)
		return false;

	std::string line;
	std::getline(file, line);

	while (std::getline(file, line))
	{
		std::stringstream stream(line);
		std::string date;
		std::string rate;

		if (!std::getline(stream, date, ','))
			continue;

		if (!std::getline(stream, rate))
			continue;

		_rates[trim(date)] = std::strtod(rate.c_str(), NULL);
	}

	return true;
}

double BitcoinExchange::findRate(const std::string& date) const
{
	std::map<std::string, double>::const_iterator it;

	it = _rates.lower_bound(date);

	if (it == _rates.end())
	{
		--it;
		return it->second;
	}

	if (it->first == date)
		return it->second;

	if (it == _rates.begin())
		return it->second;

	--it;
	return it->second;
}

void BitcoinExchange::processFile(const std::string& filename) const
{
	std::ifstream file(filename.c_str());

	if (!file)
	{
		std::cout << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	std::getline(file, line);

	while (std::getline(file, line))
	{
		size_t separator = line.find('|');

		if (separator == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = trim(line.substr(0, separator));
		std::string valueText = trim(line.substr(separator + 1));

		if (!validDate(date))
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		double value;

		if (!validValue(valueText, value))
			continue;

		double rate = findRate(date);

		std::cout << date << " => "
				  << value << " = "
				  << value * rate << std::endl;
	}
}