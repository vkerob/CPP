#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int	main()
{
	try
	{
		Bureaucrat bureaucrat1("bureaucrat1", 1);
		RobotomyRequestForm form1("form1");
		AForm *tmp;
		Intern	interne1;

		bureaucrat1.decreaseGrade();
		bureaucrat1.signForm(form1);
		bureaucrat1.executeForm(form1);
		tmp = interne1.makeForm("d request", "test");
		bureaucrat1.signForm(*tmp);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}

}