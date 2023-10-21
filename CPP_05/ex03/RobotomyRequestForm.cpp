#include "RobotomyRequestForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm()
{
	_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(std::string name, int gradeToSigned, int gradeToExec, std::string target) : AForm(name, gradeToSigned, gradeToExec), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & src ) : AForm(src), _target(src._target)
{
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RobotomyRequestForm &				RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
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

void	RobotomyRequestForm::beSigned(Bureaucrat b)
{
	if (b.getGrade() <= ROBOTOMY_MIN_GRADE_SIGN)
		setIsSigned();
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	static bool nb = false;
	if (executor.getGrade() > ROBOTOMY_MIN_GRADE_EXEC)
		throw Bureaucrat::GradeTooLowException();
	if (!getIsSigned())
		throw UnsignedForm();
	if (executor.getGrade() <= ROBOTOMY_MIN_GRADE_EXEC && getIsSigned())
	{
		std::cout << "Rrrrrrrrr... Rrrrrrrrr... Rrrrrrrrr...: ";
		if (nb)
			std::cout << getTarget() << " was robotomized " << std::endl;
		else
			std::cout << getTarget() << " robotization fails " << std::endl;
		nb = !nb;
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	RobotomyRequestForm::getTarget() const
{
	return (_target);
}

/* ************************************************************************** */