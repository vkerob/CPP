#include "AMateria.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AMateria::AMateria()
{
	this->type = "default";
	equipeOrNot = 0;
}

AMateria::AMateria(std::string const &type)
{
	this->type = type;
	equipeOrNot = 0;
}

AMateria::AMateria( const AMateria & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AMateria::~AMateria()
{
	
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AMateria &				AMateria::operator=( AMateria const & rhs )
{
	if ( this != &rhs )
	{
		type = rhs.getType();
		equipeOrNot = rhs.equipeOrNot;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, AMateria const & i )
{
	o << "Type = " << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void 		AMateria::use(ICharacter& target)
{
	(void) target;
	std::cout << "default materia" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const & AMateria::getType() const
{
	return (type);
}

void	AMateria::setEquipeOrNot(void)
{
	equipeOrNot = !equipeOrNot;
}

bool	AMateria::getEquipeOrNot( void ) const
{
	return (equipeOrNot);
}


/* ************************************************************************** */