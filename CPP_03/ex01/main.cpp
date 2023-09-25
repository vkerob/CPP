#include"ClapTrap.hpp"
#include"ScavTrap.hpp"

void	displayInfo(ScavTrap &ScavTrap)
{
	std::cout << std::endl;
	std::cout << "name: " << ScavTrap.getName() << std::endl;
	std::cout << "hit points: " << ScavTrap.getHitPoint() << std::endl;
	std::cout << "energy point: " << ScavTrap.getEnergyPoint() << std::endl;
	std::cout << "attack damage: " << ScavTrap.getAttackDamage() << std::endl;
	std::cout << std::endl;
}


int	main(void)
{
	ScavTrap npc1("gunsmith npc");
	ScavTrap npc2("farmer npc");
	ScavTrap npc3("librarian npc");
	ScavTrap npc4("guard npc");



//---------------gunsmith npc---------------//
	std::cout << std::endl;
	std::cout << "\033[31m//---------------gunsmith npc---------------//\033[0m" <<std::endl;
	displayInfo(npc1);
	while (npc1.getEnergyPoint() > 0)
		npc1.attack(npc2.getName());
	npc1.attack(npc2.getName());
	displayInfo(npc1);



//---------------farmer npc---------------//
	std::cout << "\033[32m//---------------farmer npc---------------//\033[0m" <<std::endl;
	displayInfo(npc2);
	while (npc2.getHitPoint() > 0)
		npc2.takeDamage(20);
	npc2.takeDamage(20);
	displayInfo(npc2);



//---------------librarian npc---------------//
	std::cout << "\033[94m//---------------librarian npc---------------//\033[0m" <<std::endl;
	displayInfo(npc3);
	while (npc3.getEnergyPoint() > 0)
		npc3.beRepaired(5);
	npc3.beRepaired(5);
	displayInfo(npc3);
	
//---------------guard npc---------------//
	std::cout << "\033[90m//---------------guard npc---------------//\033[0m" <<std::endl;
	displayInfo(npc4);
	while (npc4.getEnergyPoint() > 0)
		npc4.guardGate();
	npc4.guardGate();
	displayInfo(npc4);
}