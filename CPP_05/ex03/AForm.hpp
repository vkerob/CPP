#ifndef AAForm_HPP
# define AAForm_HPP

# include <iostream>
# include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{

	private:

		std::string const	_name;
		bool				_isSigned;
		int	const			_gradeExec;
		int const			_gradeSign;
		AForm &		operator=( AForm const & rhs );

	public:

		AForm();
		AForm(std::string name, int gradeToSigned, int gradeToExec);
		AForm( AForm const & src );
		virtual ~AForm();


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


		class UnsignedForm : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("the form is unsigned");
				}
		};


		void		setIsSigned(void);
		int			getGradeToExec(void) const;
		int			getGradeToSign(void) const;
		std::string	getName(void) const;
		int			getIsSigned(void) const;


		virtual void	beSigned(Bureaucrat b) = 0;
		virtual void	execute(Bureaucrat const & executor) const = 0;

};

std::ostream &			operator<<( std::ostream & o, AForm const & i );

#endif /* *********************************************************** AAForm_H */