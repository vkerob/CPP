#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>

template <typename T> 
class Array
{

	private:

		unsigned int	_n;
		T			*_array;

	public:

		Array();
		Array(unsigned int n);
		Array( Array const & src );
		~Array();


		Array &		operator=( Array const & rhs );
		T&			operator[](size_t i);


		T		getArray(unsigned int i);
		void	setArray(T value, unsigned int i);


		unsigned int	size();




};

#include "Array.tpp"

#endif /* *************************************************************** ARRAY_HPP */