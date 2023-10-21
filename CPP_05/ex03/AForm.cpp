#include "AForm.hpp"

AForm::AForm()
	: _name("default"),
	_isSigned(0),
	_gradeExec(150),
	_gradeSign(150)
{
}

AForm::AForm(std::string name, int gradeToSigned, int gradeToExec) 
	:  _name(name),
	_isSigned(0),
	_gradeExec(gradeToExec),
	_gradeSign(gradeToSigned)
{
	if (gradeToSigned > 150 || gradeToExec > 150)
		throw AForm::GradeTooHighException();
	else if (gradeToSigned < 1 || gradeToExec < 1)
		throw AForm::GradeTooLowException();
}

AForm::AForm( const AForm & src ) 
	: _name(src.getName()),
	_isSigned(src.getIsSigned()),
	_gradeExec(src.getGradeToExec()),
	_gradeSign(src.getGradeToSign())
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AForm::~AForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AForm &				AForm::operator=( AForm const & rhs )
{
	if ( this != &rhs )
	{
		this->_isSigned = rhs.getIsSigned();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, AForm const & i )
{
	o << "name: " << i.getName() << std::endl;
	o << "signed: " << i.getIsSigned() << std::endl;

	if (i.getGradeToSign() > 150)
		throw AForm::GradeTooHighException();
	else if (i.getGradeToSign() < 1)
		throw AForm::GradeTooLowException();
	else
		o << "grade to sign: " << i.getGradeToSign() << std::endl;
	if (i.getGradeToExec() > 150)
		throw AForm::GradeTooHighException();
	else if (i.getGradeToExec() < 1)
		throw AForm::GradeTooLowException();
	else
		o << "grade to exec: " << i.getGradeToExec() << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void	AForm::setIsSigned(void)
{
	_isSigned = true;
}


std::string	AForm::getName(void) const
{
	return (_name);
}

int			AForm::getGradeToSign(void) const
{
	return (_gradeSign);
}

int			AForm::getGradeToExec(void) const
{
	return (_gradeExec);
}

int			AForm::getIsSigned(void) const
{
	return (_isSigned);
}


/* ************************************************************************** */