#include "Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat() : Animal()
{
	setType("Cat");
	_brain = new Brain();
	std::cout << "Cat was created" <<std::endl;
}

Cat::Cat( const Cat & src ) : Animal(src)
{
	std::cout << "Copy constructor called" << std::endl;
	_brain = new Brain();
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat()
{
	delete _brain;
	std::cout << "Cat was destroyed" <<std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat &				Cat::operator=( Cat const & rhs )
{
	if ( this != &rhs )
	{
		Animal::operator=(rhs);
		delete _brain;
		_brain = new br
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Cat const & i )
{
	o << "type = " << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	Cat::makeSound(void) const
{
	std::cout << "miaou" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void		Cat::setBrainString(std::string str, int i)
{
	_brain->setIdeasString(str, i);
}

std::string	Cat::getBrainString(int i) const
{
	return (_brain->getIdeasString(i));
}

/* ************************************************************************** */