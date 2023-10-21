#include "PresidentialPardonForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm()
{
	_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(std::string name, int gradeToSigned, int gradeToExec, std::string target) : AForm(name, gradeToSigned, gradeToExec), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm & src ) : AForm(src), _target(src._target)
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PresidentialPardonForm::~PresidentialPardonForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PresidentialPardonForm &				PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs )
{
	if ( this != &rhs )
	{
		//this->_isSigned = rhs.getIsSigned();
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	PresidentialPardonForm::beSigned(Bureaucrat b)
{
	if (b.getGrade() <= PRESIDENTIAL_MIN_GRADE_SIGN)
		setIsSigned();
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > PRESIDENTIAL_MIN_GRADE_EXEC)
		throw Bureaucrat::GradeTooLowException();
	if (!getIsSigned())
		throw UnsignedForm();
	if (executor.getGrade() <= PRESIDENTIAL_MIN_GRADE_EXEC && getIsSigned())
		std::cout << getTarget() << " was pardoned by Zaphod Beeblebrox" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	PresidentialPardonForm::getTarget() const
{
	return (_target);
}

/* ************************************************************************** */