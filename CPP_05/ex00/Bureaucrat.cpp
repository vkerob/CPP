#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat()
{
}

Bureaucrat::Bureaucrat( const Bureaucrat & src )
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Bureaucrat &				Bureaucrat::operator=( Bureaucrat const & rhs )
{
	if ( this != &rhs )
	{
		this->_grade = rhs.getGrade();
		this->_name = rhs.getName();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i )
{
	o << i.getName << "  bureaucrat grade " << i.getGrade();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	Bureaucrat::increaseGrade(void)
{
	_grade--;
}

void	Bureaucrat::decreaseGrade(void)
{
	_grade++;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	Bureaucrat::getName(void)
{
	return (_name);
}

int			Bureaucrat::getGrade(void)
{
	return (_grade);
}


/* ************************************************************************** */