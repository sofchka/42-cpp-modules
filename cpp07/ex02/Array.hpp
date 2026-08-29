#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T>
class Array
{
	private:
		T				*_elements;
		unsigned int	_count;

	public:
		Array() : _elements(NULL), _count(0)
		{
		}

		Array(unsigned int size) : _elements(NULL), _count(size)
		{
			if (_count > 0)
				_elements = new T[_count]();
		}

		Array(const Array& other) : _elements(NULL), _count(0)
		{
			*this = other;
		}

		~Array()
		{
			delete[] _elements;
		}

		Array& operator=(const Array& other)
		{
			if (this != &other)
			{
				T* newElements = NULL;

				if (other._count > 0)
				{
					newElements = new T[other._count];

					for (unsigned int index = 0;
						index < other._count;
						++index)
					{
						newElements[index] = other._elements[index];
					}
				}

				delete[] _elements;
				_elements = newElements;
				_count = other._count;
			}

			return *this;
		}

		T& operator[](unsigned int index)
		{
			if (index >= _count)
				throw std::exception();

			return _elements[index];
		}

		const T& operator[](unsigned int index) const
		{
			if (index >= _count)
				throw std::exception();

			return _elements[index];
		}

		unsigned int size() const
		{
			return _count;
		}
};

#endif