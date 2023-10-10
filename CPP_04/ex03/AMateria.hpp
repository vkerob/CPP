#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class ICharacter;
class AMateria
{

	protected:

		std::string	type;
		int			equipeOrNot;

	public:

		AMateria();
		AMateria(std::string const &type);
		AMateria( AMateria const & src );
		virtual ~AMateria();

		AMateria &		operator=( AMateria const & rhs );


		std::string const & getType() const;
		void				setEquipeOrNot(int i);


		virtual AMateria*	clone() const = 0;
		virtual void 		use(ICharacter& target);


};

std::ostream &			operator<<( std::ostream & o, AMateria const & i );

#endif /* ******************************************************** AMATERIA_H */