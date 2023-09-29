#ifndef DOG_HPP
# define DOG_HPP

#include "Brain.hpp"
# include "Animal.hpp"
# include <iostream>
# include <string>

class Dog : public Animal
{

	private :

		Brain* _brain;

	public:

		Dog();
		Dog( Dog const & src );
		~Dog();


		Dog &		operator=( Dog const & rhs );


		void	makeSound(void) const;

		void		setBrainString(std::string str, int i);
		std::string	getBrainString(int i) const;
};

std::ostream &			operator<<( std::ostream & o, Dog const & i );

#endif /* ************************************************************* DOG_H */