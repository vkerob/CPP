#include "ShrubberyCreationForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm() : AForm()
{
	_target = "default";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(), _target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name, int gradeToSigned, int gradeToExec, std::string target) : AForm(name, gradeToSigned, gradeToExec), _target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & src ) : _target(src._target)
{
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ShrubberyCreationForm &				ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
	if ( this != &rhs )
	{
		this->_target = rhs.getTarget();
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	ShrubberyCreationForm::beSigned(Bureaucrat b)
{
	if (b.getGrade() <= SHRUBBERY_MIN_GRADE_SIGN)
		setIsSigned();
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > SHRUBBERY_MIN_GRADE_EXEC)
		throw Bureaucrat::GradeTooLowException();
	if (!getIsSigned())
		throw UnsignedForm();
	if (executor.getGrade() <= SHRUBBERY_MIN_GRADE_EXEC && getIsSigned())
	{
		std::string output = getTarget() + "_shrubbery";

		std::ofstream outputFile(output.c_str());
		if (outputFile.is_open())
		{
			outputFile << "  *  " << std::endl;
			outputFile << " *** " << std::endl;
			outputFile << "*****" << std::endl;
			outputFile << "  |  " << std::endl;
			outputFile.close();
		}
		else
			std::cerr << "Error Impossible to open the file" << std::endl;
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	ShrubberyCreationForm::getTarget() const
{
	return (_target);
}

/* ************************************************************************** */