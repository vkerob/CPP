#include"ClapTrap.hpp"
#include"ScavTrap.hpp"
#include"FragTrap.hpp"
#include"DiamondTrap.hpp"

void	displayInfo(DiamondTrap &DiamondTrap)
{
	std::cout << std::endl;
	std::cout << "name: " << DiamondTrap.getName() << std::endl;
	std::cout << "hit points: " << DiamondTrap.getHitPoint() << std::endl;
	std::cout << "energy point: " << DiamondTrap.getEnergyPoint() << std::endl;
	std::cout << "attack damage: " << DiamondTrap.getAttackDamage() << std::endl;
}


int	main(void)
{
	DiamondTrap npc1("gunsmith npc");
	DiamondTrap npc2("farmer npc");
	DiamondTrap npc3("librarian npc");
	DiamondTrap npc4("guard npc");


//---------------gunsmith npc---------------//
	std::cout << "\033[31m//---------------gunsmith npc---------------//\033[0m" <<std::endl;
	displayInfo(npc1);
	while (npc1.getEnergyPoint() > 0)
		npc1.attack(npc2.getName());
	npc1.attack(npc2.getName());
	npc1.highFivesGuys();
	displayInfo(npc1);



//---------------farmer npc---------------//
	std::cout << "\033[32m//---------------farmer npc---------------//\033[0m" <<std::endl;
	displayInfo(npc2);
	while (npc2.getHitPoint() > 0)
		npc2.takeDamage(30);
	npc2.takeDamage(30);
	npc2.highFivesGuys();
	displayInfo(npc2);



//---------------librarian npc---------------//
	std::cout << "\033[94m//---------------librarian npc---------------//\033[0m" <<std::endl;
	displayInfo(npc3);
	while (npc3.getEnergyPoint() > 0)
		npc3.beRepaired(5);
	npc3.beRepaired(5);
	npc3.highFivesGuys();
	displayInfo(npc3);



//---------------guard npc---------------//
	std::cout << "\033[90m//---------------guard npc---------------//\033[0m" <<std::endl;
	displayInfo(npc4);
	while (npc4.getEnergyPoint() > 0)
		npc4.guardGate();
	npc4.guardGate();
	npc4.whoAmI();
	displayInfo(npc4);


}