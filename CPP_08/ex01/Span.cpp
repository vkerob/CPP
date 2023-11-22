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
		this->_list = rhs._list;
	}
	return *this;
}

void	Span::addNumber(int nb)
{
	if (_list.size() < _max_number && _list.size() < _list.max_size())
		_list.push_back(nb);
	else
		throw std::logic_error("list is to small");
}

void	Span::addManyNumber(std::list<int> &list_tmp)
{
	if (list_tmp.size() > _max_number - _list.size() && list_tmp.size() + _list.size() < _list.max_size())
		throw std::logic_error("list is to small");
	std::list<int>::iterator it1_start = _list.begin();
	_list.splice(it1_start, list_tmp);
}

int		Span::shortestSpan()
{
	if (_list.size() < 2)
		throw std::logic_error("array size must be greater than 2 ");
	_list.sort();
	std::list<int>::iterator it_tmp = _list.begin();
	std::list<int>::iterator it_tmp_p = it_tmp++;
	unsigned int tmp = 4294967295;

	for (int i = 1; static_cast<unsigned long>(i) < _list.size(); i++)
	{
		if (static_cast<unsigned int>(*it_tmp) - static_cast<unsigned int>(*it_tmp_p) < tmp)
			tmp = *it_tmp - *it_tmp_p;
		it_tmp++;
		it_tmp_p++;
	}
	return (tmp);

}

int		Span::longestSpan()
{
	if (_list.size() < 2)
		throw std::logic_error("array size must be greater than 2 ");
	_list.sort();
	std::list<int>::iterator it1 = _list.begin();
	std::list<int>::reverse_iterator it2 = _list.rbegin();
	return (*it2 - *it1);
}

std::list<int> &Span::getList()
{
	return (_list);
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */