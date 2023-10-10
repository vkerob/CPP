#include "Character.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Character::Character(std::string name)
{
	_name = name;
	for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
}

Character::Character( const Character & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
		{
			delete _inventory[i];
			_inventory[i] = NULL;
		}
	}
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Character &				Character::operator=( Character const & rhs )
{
	if ( this != &rhs )
	{
		for (int i = 0; i < 4; i++)
		{
			if (_inventory[i])
			{
				delete _inventory[i];
				_inventory[i] = NULL;
			}
			if (rhs._inventory[i])
				_inventory[i] = rhs._inventory[i]->clone();
		}
		_name = rhs._name;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Character const & i )
{
	o << "name = " << i.getName();
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
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			_inventory[i]->setEquipeOrNot(1);
			return ;
		}
	}
}


void Character::unequip(int idx)
{
	if (_inventory[idx] != NULL)
	{
		_inventory[idx]->setEquipeOrNot(0);
		_inventory[idx] = NULL;
	}
}


void Character::use(int idx, ICharacter& target)
{
	_inventory[idx]->use(target);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const & Character::getName() const
{
	return (_name);
}

/* ************************************************************************** */