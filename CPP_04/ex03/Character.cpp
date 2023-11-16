#include "Character.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Character::Character()
{
	_name = "default";
	for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
}


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
		if (_inventory[i] != NULL)
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
	if (m == NULL)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == NULL && m->getEquipeOrNot() == false)
		{
			_inventory[i] = m;
			_inventory[i]->setEquipeOrNot();
			return ;
		}
		else if (m->getEquipeOrNot() == true)
		{
			std::cout << "already equipe" << std::endl;
			return ;
		}
	}
	std::cout << "full inventory" << std::endl;
}


void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
	{
		std::cout << "out of range" << std::endl;
		return ;
	}
	if (_inventory[idx] != NULL)
	{
		_inventory[idx]->setEquipeOrNot();
		_inventory[idx] = NULL;
	}
}


void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4)
	{
		std::cout << "out of range" << std::endl;
		return ;
	}
	if (_inventory[idx] != NULL)
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