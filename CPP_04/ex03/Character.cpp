#include "Character.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Character::Character(std::string name)
{
	inventory[0] = NULL;
	inventory[1] = NULL;
	inventory[2] = NULL;
	inventory[3] = NULL;
}

Character::Character( const Character & src )
{
	
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Character::~Character()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Character &				Character::operator=( Character const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Character const & i )
{
	//o << "Value = " << i.getValue();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		//new m ?
		if (inventory[i] == NULL)
			inventory[i] = m;
	}
}


void Character::unequip(int idx)
{
	if (inventory[idx] != NULL)
		inventory[idx] = NULL;
}


void Character::use(int idx, ICharacter& target)
{
	inventory[idx]->use(target);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const & Character::getName() const
{
	
}

/* ************************************************************************** */