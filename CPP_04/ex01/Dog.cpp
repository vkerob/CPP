#include "Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog()
{
	setType("Dog");
	_brain = new Brain();
	std::cout << "Dog was created" <<std::endl;
}

Dog::Dog( const Dog & src ) : Animal(src)
{
	std::cout << "Copy constructor called" << std::endl;
	_brain = new Brain();
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog()
{
	delete _brain;
	std::cout << "Dog was destroyed" <<std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog &				Dog::operator=( Dog const & rhs )
{
	if ( this != &rhs )
	{
		this->_type = rhs.getType();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Dog const & i )
{
	o << "type = " << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	Dog::makeSound(void) const
{
	std::cout << "wouf" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void		Dog::setBrainString(std::string str, int i)
{
	_brain->setIdeasString(str, i);
}

std::string	Dog::getBrainString(int i) const
{
	return(_brain->getIdeasString(i));
}


/* ************************************************************************** */