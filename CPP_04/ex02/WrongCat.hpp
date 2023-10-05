#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"
# include "Brain.hpp"
# include <iostream>
# include <string>

class WrongCat : public WrongAnimal
{

	private :

		Brain* _brain;

	public:

		WrongCat();
		WrongCat( WrongCat const & src );
		~WrongCat();


		WrongCat &		operator=( WrongCat const & rhs );


		void	makeSound(void) const;


		void		setBrainString(std::string str, int i);
		std::string	getBrainString(int i) const;
};

std::ostream &			operator<<( std::ostream & o, WrongCat const & i );

#endif /* ******************************************************** WRONGCAT_H */