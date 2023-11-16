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
	AMateria* tmp2;
	AMateria* tmp3;
	AMateria* tmp4;
	AMateria* tmp5;
	tmp1 = src->createMateria("ice");
	tmp2 = src->createMateria("cure");
	tmp3 = src->createMateria("cure");
	tmp4 = src->createMateria("ice");
	tmp5 = src->createMateria("sqwfuofwuo");
	me->equip(tmp1);
	me->equip(tmp2);
	me->equip(tmp3);
	me->equip(tmp4);
	me->equip(tmp5);
	me->use(3, *bob);
	bob->equip(tmp5);
	me->unequip(0);
	me->use(0, *bob);



	delete bob;
	delete me;
	delete src;
	//delete tmp1;
	//delete tmp2;
	return 0;

}