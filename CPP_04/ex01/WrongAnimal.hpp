#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal
{
	protected :

		std::string	_type;

	public:

		WrongAnimal();
		WrongAnimal( WrongAnimal const & src );
		~WrongAnimal();


		WrongAnimal &		operator=( WrongAnimal const & rhs );


		void	makeSound(void) const;
		

		void	setType(std::string str);
		std::string	getType(void) const;

};

std::ostream &			operator<<( std::ostream & o, WrongAnimal const & i );

#endif /* ***************************************************** WRONGANIMAL_H */