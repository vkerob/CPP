#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# define PRESIDENTIAL_MIN_GRADE_SIGN 25
# define PRESIDENTIAL_MIN_GRADE_EXEC 5

# include <iostream>
# include <string>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{

	private:

		std::string	_target;
		PresidentialPardonForm &		operator=( PresidentialPardonForm const & rhs );
		void	execute(Bureaucrat const & executor) const;
		void	beSigned(Bureaucrat b);

	public:

		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(std::string name, int gradeToSigned, int gradeToExec, std::string target);
		PresidentialPardonForm( PresidentialPardonForm const & src );
		~PresidentialPardonForm();


		std::string	getTarget() const;
		


};

//std::ostream &			operator<<( std::ostream & o, PresidentialPardonForm const & i );

#endif /* ****************************************** PRESIDENTIALPARDONFORM_H */