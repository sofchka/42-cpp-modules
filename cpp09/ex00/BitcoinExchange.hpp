#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange
{
	private:
		std::map<std::string, double> _rates;

		bool validDate(const std::string& date) const;
		bool validValue(const std::string& text, double& value) const;
		std::string trim(const std::string& text) const;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		bool readDatabase(const std::string& filename);
		void processFile(const std::string& filename) const;
		double findRate(const std::string& date) const;
};

#endif