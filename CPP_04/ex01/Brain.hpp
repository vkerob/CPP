#ifndef BRAIN_HPP
# define BRAIN_HPP


#include "Animal.hpp"
# include <iostream>
# include <string>
# include <cstring>

class Brain
{

	private:

		std::string _ideas[100];

	public:

		Brain();
		Brain( Brain const & src );
		~Brain();

		Brain &		operator=( Brain const & rhs );


		void		setIdeasString(std::string str, int i);
		std::string	getIdeasString(int i) const;

};

std::ostream &			operator<<( std::ostream & o, Brain const & i );

#endif /* *********************************************************** BRAIN_H */