#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"
# include <iostream>
# include <string>

class WrongCat : WrongAnimal()
{

	public:

		WrongCat();
		WrongCat( WrongCat const & src );
		~WrongCat();

		WrongCat &		operator=( WrongCat const & rhs );

	private:

};

std::ostream &			operator<<( std::ostream & o, WrongCat const & i );

#endif /* ******************************************************** WRONGCAT_H */