#include "Intern.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern()
{
}

Intern::Intern( const Intern & src )
{
	(void)src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Intern &				Intern::operator=( Intern const & rhs )
{
	(void)rhs;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

Intern::Name	Intern::formToEnum(std::string form_name)
{
	if (form_name == "presidential request")
		return (presidential);
	if (form_name == "robotomy request")
		return (robotomy);
	if (form_name == "shrubbery request")
		return (shrubbery);
	return (unknown);
}

AForm	*Intern::makeForm(std::string form_name, std::string target)
{
	Name enum_name;
	AForm *form = NULL;

	enum_name = formToEnum(form_name);
	switch(enum_name)
	{
		case presidential:
			form = new PresidentialPardonForm(form_name, 25, 5, target);
			std::cout << "Intern create Presidential Form" << std::endl;
			break;
		case robotomy:
			form = new PresidentialPardonForm(form_name, 72, 45, target);
			std::cout << "Intern create Robotomy Form" << std::endl;
			break;
		case shrubbery:
			form = new PresidentialPardonForm(form_name, 145, 137, target);
			std::cout << "Intern create Shrubbery Form" << std::endl;
			break;
		case unknown:
			throw Intern::UnknownForm();
		default:
			std::cout << "Unknown form" << std::endl;
			break;
	}
	return (form);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */