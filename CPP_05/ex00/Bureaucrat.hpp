#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class Bureaucrat
{

	private:

		std::string	_name;
		int			_grade;

	public:

		Bureaucrat();
		Bureaucrat( Bureaucrat const & src );
		~Bureaucrat();


		std::string	getName(void);
		int			getGrade(void);


		Bureaucrat &		operator=( Bureaucrat const & rhs );


		void	increaseGrade(void);
		void	decreaseGrade(void);

};

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i );

#endif /* ****************************************************** BUREAUCRAT_H */