#include "AAnimal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AAnimal::AAnimal() : _type("")
{
	std::cout << "AAnimal was created" <<std::endl;
}

AAnimal::AAnimal( const AAnimal & src )
{
	std::cout << "AAnimal Copy constructor called" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AAnimal::~AAnimal()
{
	std::cout << "AAnimal was destroyed" <<std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AAnimal &				AAnimal::operator=( AAnimal const & rhs )
{
	if ( this != &rhs )
	{
		this->_type = rhs.getType();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, AAnimal const & i )
{
	o << "type = " << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	AAnimal::makeSound(void) const
{
	std::cout << "..." << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void	AAnimal::setType(std::string str)
{
	_type = str;
}

std::string	AAnimal::getType(void) const
{
	return (_type);
}


/* ************************************************************************** */