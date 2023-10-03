#include "Animal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Animal::Animal() : _type("")
{
	std::cout << "Animal was created" <<std::endl;
}

Animal::Animal( const Animal & src )
{
	std::cout << "Animal Copy constructor called" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Animal::~Animal()
{
	std::cout << "Animal was destroyed" <<std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Animal &				Animal::operator=( Animal const & rhs )
{
	if ( this != &rhs )
	{
		this->_type = rhs.getType();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Animal const & i )
{
	o << "type = " << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	Animal::makeSound(void) const
{
	std::cout << "..." << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void	Animal::setType(std::string str)
{
	_type = str;
}

std::string	Animal::getType(void) const
{
	return (_type);
}


/* ************************************************************************** */