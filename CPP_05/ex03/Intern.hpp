#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class AForm;

class Intern
{

	private:
		enum 			Name {presidential, robotomy, shrubbery, unknown};
		Intern &		operator=( Intern const & rhs );
		Intern( Intern const & src );

	public:

		Intern();
		~Intern();


		class UnknownForm : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Unknown form");
				}
		};


		AForm			*makeForm(std::string formName, std::string target);
		int				formToEnum(std::string form_name);

};

//std::ostream &			operator<<( std::ostream & o, Intern const & i );

#endif /* ********************************************************** INTERN_H */