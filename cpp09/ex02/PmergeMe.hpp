#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>

class PmergeMe
{
	private:
		std::vector<int> _vector;
		std::deque<int> _deque;

		void sortVector(std::vector<int>& values);
		void sortDeque(std::deque<int>& values);

		void insertVector(std::vector<int>& values, int value, size_t limit);
		void insertDeque(std::deque<int>& values, int value, size_t limit);

		size_t upperBoundVector(const std::vector<int>& values,
								int value, size_t limit) const;
		size_t upperBoundDeque(const std::deque<int>& values,
							   int value, size_t limit) const;

		std::vector<size_t> jacobsthal(size_t count) const;
		std::deque<size_t> jacobsthalDeque(size_t count) const;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		void parseInput(int argc, char** argv);

		void sortWithVector();
		void sortWithDeque();

		void printBefore() const;
		void printAfter() const;

		const std::vector<int>& getVector() const;
		const std::deque<int>& getDeque() const;
};

#endif