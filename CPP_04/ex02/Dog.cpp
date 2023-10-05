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

Dog::Dog( const Dog & src ) : AAnimal(src)
{
	std::cout << "Copy constructor called" << std::endl;
	_brain = new Brain(*src._brain);
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
		AAnimal::operator=(rhs);
		delete _brain;
		_brain = new Brain(*rhs._brain);
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
	if (i < 0 || i > 99)
	{
		std::cout << "out of range" << std::endl;
		return;
	}
	_brain->setIdeasString(str, i);
}

std::string	Dog::getBrainString(int i) const
{
	if (i < 0 || i > 99)
		return ("out of range");
	return(_brain->getIdeasString(i));
}


/* ************************************************************************** */