#include "Brain.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Brain::Brain()
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = "test";
}

Brain::Brain( const Brain & src )
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = src._ideas[i];
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Brain::~Brain()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Brain &				Brain::operator=( Brain const & rhs )
{
	if ( this != &rhs )
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = rhs._ideas[i];
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Brain const & i )
{
	for (int j = 0; j < 100; j++)
		o << i.getIdeasString(j);
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void	Brain::setIdeasString(std::string str, int i)
{
	_ideas[i] = str;
}

std::string	Brain::getIdeasString(int i) const
{
	return (_ideas[i]);
}


/* ************************************************************************** */