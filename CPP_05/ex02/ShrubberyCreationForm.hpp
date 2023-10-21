#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# define SHRUBBERY_MIN_GRADE_SIGN 145
# define SHRUBBERY_MIN_GRADE_EXEC 137

# include <iostream>
# include <string>
# include<fstream>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{

	private:

		std::string	_target;
		ShrubberyCreationForm &		operator=( ShrubberyCreationForm const & rhs );
		void	execute(Bureaucrat const & executor) const;
		void	beSigned(Bureaucrat b);

	public:

		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(std::string name, int gradeToSigned, int gradeToExec, std::string target);
		ShrubberyCreationForm( ShrubberyCreationForm const & src );
		~ShrubberyCreationForm();


		std::string	getTarget() const;

};

//std::ostream &			operator<<( std::ostream & o, ShrubberyCreationForm const & i );

#endif /* ******************************************* SHRUBBERYCREATIONFORM_H */