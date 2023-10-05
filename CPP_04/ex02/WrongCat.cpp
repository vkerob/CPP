#include "WrongCat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "WrongCat was created" <<std::endl;
	_brain = new Brain();
}

WrongCat::WrongCat( const WrongCat & src ) : WrongAnimal(src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongCat::~WrongCat()
{
	delete _brain;
	std::cout << "WrongCat was destroyed" <<std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongCat &				WrongCat::operator=( WrongCat const & rhs )
{
	if ( this != &rhs )
	{
		this->_type = rhs.getType();
		this->_brain = rhs._brain;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, WrongCat const & i )
{
	o << "type = " << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	WrongCat::makeSound(void) const
{
	std::cout << "miaou" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


void		WrongCat::setBrainString(std::string str, int i)
{
	if (i < 0 || i > 99)
	{
		std::cout << "out of range" << std::endl;
		return;
	}
	_brain->setIdeasString(str, i);
}

std::string	WrongCat::getBrainString(int i) const
{
	if (i < 0 || i > 99)
		return ("out of range");
	return (_brain->getIdeasString(i));
}


/* ************************************************************************** */