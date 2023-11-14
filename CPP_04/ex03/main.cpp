#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"



int main()
{

	IMateriaSource* src = new MateriaSource();
	//AMateria* test = new Ice();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	
	ICharacter* bob = new Character("bob");

	AMateria* tmp1;
	tmp1 = src->createMateria("ice");
	me->equip(tmp1);
	me->use(0, *bob);
	me->unequip(0);
	AMateria* tmp2;
	tmp2 = src->createMateria("cure");
	me->equip(tmp2);


	me->use(0, *bob);
	me->use(1, *bob);
	me->use(4, *bob);

	me->unequip(0);
	me->use(2, *bob);


	delete bob;
	delete me;
	delete src;
	delete tmp1;
	delete tmp2;
	return 0;

}