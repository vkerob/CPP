#ifndef CAT_HPP
# define CAT_HPP

#include "Brain.hpp"
# include "AAnimal.hpp"
# include <iostream>
# include <string>

class Cat : public AAnimal
{
	
	private :

		Brain* _brain;

	public:

		Cat();
		Cat( Cat const & src );
		~Cat();


		Cat &		operator=( Cat const & rhs );


		void	makeSound(void) const;


		void		setBrainString(std::string str, int i);
		std::string	getBrainString(int i) const;
};

std::ostream &			operator<<( std::ostream & o, Cat const & i );

#endif /* ************************************************************* CAT_H */