#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
#include "Form.hpp"

class Form;

class Bureaucrat
{

	private:

		const std::string	_name;
		int					_grade;
		Bureaucrat &		operator=( Bureaucrat const & rhs );
		Bureaucrat( Bureaucrat const & src );

	public:

		Bureaucrat();
		Bureaucrat(std::string name, int grade);
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


		void		setGrade(int grade);
		std::string	getName(void) const;
		int			getGrade(void) const;




		void	increaseGrade(void);
		void	decreaseGrade(void);
		void	signForm(Form f);

};

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i );

#endif /* ****************************************************** BUREAUCRAT_H */