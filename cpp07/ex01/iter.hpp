#ifndef ITER_HPP
#define ITER_HPP

template <typename T, typename Function>
void iter(T* array, const unsigned int length, Function function)
{
	if (array == NULL)
		return;

	for (unsigned int index = 0; index < length; ++index)
		function(array[index]);
}

template <typename T, typename Function>
void iter(const T* array, const unsigned int length, Function function)
{
	if (array == NULL)
		return;

	for (unsigned int index = 0; index < length; ++index)
		function(array[index]);
}

#endif