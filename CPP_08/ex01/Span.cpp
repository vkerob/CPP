#include "Span.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Span::Span()
{
	_max_number = 0;
}

Span::Span(unsigned int nb)
{
	_max_number = nb;
}

Span::Span( const Span & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Span::~Span()
{

}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Span &				Span::operator=( Span const & rhs )
{
	if ( this != &rhs )
	{
		this->_max_number = rhs._max_number;
		this->_list1 = rhs._list1;
	}
	return *this;
}

void	Span::addNumber(int nb)
{
	if (_list1.size() < _max_number && _list1.size() < _list1.max_size())
		_list1.push_back(nb);
}

void	Span::addManyNumber(std::list<int> &list2)
{
	if (list2.size() > _max_number - _list1.size() && list2.size() + _list1.size() < _list1.max_size())
		throw std::logic_error("list is to small");
	std::list<int>::iterator it1_start = _list1.begin();
	_list1.splice(it1_start, list2);
}

int		Span::shortestSpan()
{
	if (_list1.size() < 2)
		throw std::logic_error("array size must be greater than 2 ");
	_list1.sort();
	std::list<int>::iterator it_tmp = _list1.begin();
	std::list<int>::iterator it_tmp_p = it_tmp++;
	int	tmp = *it_tmp;

	for (int i = 1; static_cast<unsigned long>(i) < _list1.size() - 1; i++)
	{
		if (*it_tmp - *it_tmp_p > 0 && *it_tmp - *it_tmp_p < tmp)
			tmp = *it_tmp - *it_tmp_p;
		it_tmp++;
		it_tmp_p++;
	}
	return (tmp);

}

int		Span::longestSpan()
{
	if (_list1.size() < 2)
		throw std::logic_error("array size must be greater than 2 ");
	_list1.sort();
	std::list<int>::iterator it1 = _list1.begin();
	std::list<int>::reverse_iterator it2 = _list1.rbegin();
	return (*it2 - *it1);


}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */