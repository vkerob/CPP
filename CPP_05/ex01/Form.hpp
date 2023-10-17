#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{

	private:

		std::string const	_name;
		bool				_isSigned;
		int	const			_gradeExec;
		int const			_gradeSign;
		Form &		operator=( Form const & rhs );

	public:

		Form();
		Form(std::string name, int gradeToSigned, int gradeToExec);
		Form( Form const & src );
		~Form();


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


		void		setIsSigned(void);
		int			getGradeToExec(void) const;
		int			getGradeToSign(void) const;
		std::string	getName(void) const;
		int			getIsSigned(void) const;


		void	beSigned(Bureaucrat b);


};

std::ostream &			operator<<( std::ostream & o, Form const & i );

#endif /* ************************************************************ FORM_H */