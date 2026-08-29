#include "BitcoinExchange.hpp"

#include <iostream>

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}

	BitcoinExchange exchange;

	if (!exchange.readDatabase("data.csv"))
	{
		std::cout << "Error: could not open database." << std::endl;
		return 1;
	}

	exchange.processFile(argv[1]);

	return 0;
}
