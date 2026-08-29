#include "PmergeMe.hpp"

#include <iostream>
#include <ctime>
#include <iomanip>

int main(int argc, char** argv)
{
	try
	{
		PmergeMe sorter;
		sorter.parseInput(argc, argv);

		sorter.printBefore();

		clock_t vectorStart = std::clock();
		sorter.sortWithVector();
		clock_t vectorEnd = std::clock();

		clock_t dequeStart = std::clock();
		sorter.sortWithDeque();
		clock_t dequeEnd = std::clock();

		sorter.printAfter();

		double vectorTime =
			static_cast<double>(vectorEnd - vectorStart)
			/ CLOCKS_PER_SEC * 1000000.0;

		double dequeTime =
			static_cast<double>(dequeEnd - dequeStart)
			/ CLOCKS_PER_SEC * 1000000.0;

		size_t count = sorter.getVector().size();

		std::cout << std::fixed << std::setprecision(5);

		std::cout << "Time to process a range of "
				  << count
				  << " elements with std::vector : "
				  << vectorTime << " us" << std::endl;

		std::cout << "Time to process a range of "
				  << count
				  << " elements with std::deque : "
				  << dequeTime << " us" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}