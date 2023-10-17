#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{

}

Bureaucrat::Bureaucrat(std::string name, int grade)
{
	_name = name;
	try
	{
		setGrade(grade);
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
		return ;
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
		return ;
	}
}

Bureaucrat::Bureaucrat( const Bureaucrat & src )
{
	*this = src;
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
	o << i.getName() << " bureaucrat grade " << i.getGrade();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	Bureaucrat::increaseGrade(void)
{
	try
	{
		if (_grade - 1 > 150)
			throw Bureaucrat::GradeTooHighException();
		else if (_grade - 1 < 1)
			throw Bureaucrat::GradeTooLowException();
		else
			_grade--;
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
		return ;
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
		return ;
	}
}

void	Bureaucrat::decreaseGrade(void)
{
	try
	{
		if (_grade + 1 > 150)
			throw Bureaucrat::GradeTooHighException();
		else if (_grade + 1 < 1)
			throw Bureaucrat::GradeTooLowException();
		else
			_grade++;
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
		return ;
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
		return ;
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void	Bureaucrat::setName(std::string name)
{
	_name = name;
}

void	Bureaucrat::setGrade(int grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooHighException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade = grade;
}


std::string	Bureaucrat::getName(void) const
{
	return (_name);
}

int			Bureaucrat::getGrade(void) const
{
	return (_grade);
}


/* ************************************************************************** */