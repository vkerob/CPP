#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"
#include <memory>

class AForm;

class Bureaucrat
{

	private:

		const std::string	_name;
		int			_grade;
		void		setGrade(int grade);

	public:

		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat( Bureaucrat const & src );
		~Bureaucrat();


		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Grade too low");
				}
		};


		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Grade too high");
				}
		};


		std::string	getName(void) const;
		int			getGrade(void) const;


		Bureaucrat &		operator=( Bureaucrat const & rhs );


		void	increaseGrade(void);
		void	decreaseGrade(void);
		void	signForm(AForm &f);
		void	executeForm(AForm const & form);

};

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i );

#endif /* ****************************************************** BUREAUCRAT_H */