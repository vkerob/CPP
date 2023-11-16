#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"
# include "AMateria.hpp"


class Character : public ICharacter
{

	private:

		AMateria *_inventory[4];
		std::string _name;


	public:

		Character();
		Character(std::string name);
		Character( Character const & src );
		~Character();

		Character &		operator=( Character const & rhs );


		virtual std::string const & getName() const;


		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);

};

std::ostream &			operator<<( std::ostream & o, Character const & i );

#endif /* ******************************************************* CHARACTER_H */