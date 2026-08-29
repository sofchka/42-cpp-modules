#include <iostream>
#include <string>

#include "iter.hpp"

template <typename T>
void printValue(const T& value)
{
	std::cout << value << std::endl;
}

void increase(int& value)
{
	++value;
}

void makeUppercase(std::string& text)
{
	for (std::string::size_type i = 0; i < text.length(); ++i)
	{
		if (text[i] >= 'a' && text[i] <= 'z')
			text[i] -= ('a' - 'A');
	}
}

int main()
{
	int scores[] = {1, 5, 9, 13, 17};
	const unsigned int scoreCount = sizeof(scores) / sizeof(scores[0]);

	std::cout << "Original numbers:" << std::endl;
	::iter(scores, scoreCount, printValue<int>);

	::iter(scores, scoreCount, increase);

	std::cout << "\nAfter increasing:" << std::endl;
	::iter(scores, scoreCount, printValue<int>);

	std::string words[] = {
		"hello",
		"templates",
		"cpp"
	};
	const unsigned int wordCount = sizeof(words) / sizeof(words[0]);

	std::cout << "\nOriginal strings:" << std::endl;
	::iter(words, wordCount, printValue<std::string>);

	::iter(words, wordCount, makeUppercase);

	std::cout << "\nUppercase strings:" << std::endl;
	::iter(words, wordCount, printValue<std::string>);

	const int fixedValues[] = {42, 84, 126};
	const unsigned int fixedCount =
		sizeof(fixedValues) / sizeof(fixedValues[0]);

	std::cout << "\nConst array:" << std::endl;
	::iter(fixedValues, fixedCount, printValue<int>);

	return 0;
}