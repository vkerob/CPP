#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form()
	: _name("default"),
	_isSigned(0),
	_gradeExec(150),
	_gradeSign(150)
{
}

Form::Form(std::string name, int gradeToSigned, int gradeToExec) 
	:  _name(name),
	_isSigned(0),
	_gradeExec(gradeToExec),
	_gradeSign(gradeToSigned)
{
	if (gradeToSigned > 150 || gradeToExec > 150)
		throw Form::GradeTooHighException();
	else if (gradeToSigned < 1 || gradeToExec < 1)
		throw Form::GradeTooLowException();
}

Form::Form( const Form & src ) 
	: _name(src.getName()),
	_isSigned(src.getIsSigned()),
	_gradeExec(src.getGradeToExec()),
	_gradeSign(src.getGradeToSign())
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form &				Form::operator=( Form const & rhs )
{
	if ( this != &rhs )
	{
		this->_isSigned = rhs.getIsSigned();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Form const & i )
{
	o << "name: " << i.getName() << std::endl;
	o << "signed: " << i.getIsSigned() << std::endl;
	if (i.getGradeToSign() > 150)
		throw Form::GradeTooHighException();
	else if (i.getGradeToSign() < 1)
		throw Form::GradeTooLowException();
	else
		o << "grade to sign: " << i.getGradeToSign() << std::endl;
	if (i.getGradeToExec() > 150)
		throw Form::GradeTooHighException();
	else if (i.getGradeToExec() < 1)
		throw Form::GradeTooLowException();
	else
		o << "grade to exec: " << i.getGradeToExec() << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	Form::beSigned(Bureaucrat b)
{
	if (b.getGrade() <= getGradeToSign())
		setIsSigned();
	else
		throw Form::GradeTooLowException();
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void	Form::setIsSigned(void)
{
	_isSigned = true;
}


std::string	Form::getName(void) const
{
	return (_name);
}

int			Form::getGradeToSign(void) const
{
	return (_gradeSign);
}

int			Form::getGradeToExec(void) const
{
	return (_gradeExec);
}

int			Form::getIsSigned(void) const
{
	return (_isSigned);
}


/* ************************************************************************** */