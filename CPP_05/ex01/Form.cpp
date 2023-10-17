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
	try
	{
		if (gradeToSigned > 150 || gradeToExec > 150)
			throw Form::GradeTooHighException();
		else if (gradeToSigned < 1 || gradeToExec < 1)
			throw Form::GradeTooLowException();
	}
	catch (const Form::GradeTooHighException& e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}
	catch (const Form::GradeTooLowException& e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}
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

	// try and catch pour _gradeToSign
	try
	{
		if (i.getGradeToSign() > 150)
			throw Form::GradeTooHighException();
		else if (i.getGradeToSign() < 1)
			throw Form::GradeTooLowException();
		else
			o << "grade to sign: " << i.getGradeToSign() << std::endl;
	}
	catch (const Form::GradeTooHighException& e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}
	catch (const Form::GradeTooLowException& e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}

	// try and catch pour _gradeToExec
	try
	{
		if (i.getGradeToExec() > 150)
			throw Form::GradeTooHighException();
		else if (i.getGradeToExec() < 1)
			throw Form::GradeTooLowException();
		else
			o << "grade to exec: " << i.getGradeToExec() << std::endl;

	}
	catch (const Form::GradeTooHighException& e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}
	catch (const Form::GradeTooLowException& e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	Form::beSigned(Bureaucrat b)
{
	if (b.getGrade() >= getGradeToSign())
		setIsSigned();
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