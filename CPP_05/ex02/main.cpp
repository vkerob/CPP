#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main()
{
	try
	{
		Bureaucrat b1("b1", 1);
		RobotomyRequestForm f1("f1");

		b1.decreaseGrade();
		b1.signForm(f1);
		b1.executeForm(f1);
		b1.executeForm(f1);
		b1.executeForm(f1);
		b1.executeForm(f1);
		b1.executeForm(f1);
		b1.executeForm(f1);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}
}