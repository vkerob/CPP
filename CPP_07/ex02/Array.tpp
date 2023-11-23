#ifndef ARRAY_TPP
# define ARRAY_TPP


# include"Array.hpp"

template <typename T>
Array<T>::Array() : _n(0)
{
	_array = NULL;
}

template <typename T>
Array<T>::Array(unsigned int n) : _n(n)
{
	if (n != 0)
		_array = new T[n];
	else
		_array = NULL;
}

template <typename T>
Array<T>::Array(Array const & src)
{
	*this = src;
}

template <typename T>
Array<T>::~Array()
{
	if (_array)
		delete [] _array;
}

template <typename T>
Array<T> &		Array<T>::operator=( Array<T> const & rhs )
{
	if ( this != &rhs )
	{
		if (this->_array)
			delete [] _array;
		if (rhs._array)
		{
			this->_array = new T[rhs.size()];
			for (int i = 0; i < rhs.size(); i++)
			{
				if (rhs._array[i])
					this->_array[i] = rhs._array[i];
			}
		}
		this->_n = rhs.size();
	}
	return (*this);
}

template <typename T>
T&			Array<T>::operator[](size_t i)
{
	if (i >= size() || i < 0 || size() == 0)
		throw (std::out_of_range("index out of range"));
	return (_array[i]);
}

template <typename T>
unsigned int	Array<T>::size()
{
	return(_n);
}

template <typename T>
T	Array<T>::getArray(unsigned int i)
{
	if (i >= size() || i < 0 || size() == 0)
		std::cout << "index out of range" << std::endl;
	else
		return (_array[i]);
}

template <typename T>
void	Array<T>::setArray(T value, unsigned int i)
{
	if (i >= size() || i < 0 || size() == 0)
		std::cout << "index out of range" << std::endl;
	else
		_array[i] = value;
}

#endif