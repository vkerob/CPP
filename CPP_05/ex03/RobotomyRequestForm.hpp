#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# define ROBOTOMY_MIN_GRADE_SIGN 72
# define ROBOTOMY_MIN_GRADE_EXEC 45

# include <iostream>
# include <string>
# include<cstdlib>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{

	private:

		std::string	_target;

	public:

		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(std::string name, int gradeToSigned, int gradeToExec, std::string target);
		RobotomyRequestForm( RobotomyRequestForm const & src );
		~RobotomyRequestForm();

		
		RobotomyRequestForm &		operator=( RobotomyRequestForm const & rhs );
		
		
		void	execute(Bureaucrat const & executor) const;
		void	beSigned(Bureaucrat b);


		std::string	getTarget() const;

};

//std::ostream &			operator<<( std::ostream & o, RobotomyRequestForm const & i );

#endif /* ********************************************* ROBOTOMYREQUESTFORM_H */