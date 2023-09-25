#include"ClapTrap.hpp"
#include"ScavTrap.hpp"
#include"FragTrap.hpp"

void	displayInfo(FragTrap &FragTrap)
{
	std::cout << std::endl;
	std::cout << "name: " << FragTrap.getName() << std::endl;
	std::cout << "hit points: " << FragTrap.getHitPoint() << std::endl;
	std::cout << "energy point: " << FragTrap.getEnergyPoint() << std::endl;
	std::cout << "attack damage: " << FragTrap.getAttackDamage() << std::endl;
}


int	main(void)
{
	FragTrap npc1("gunsmith npc");
	FragTrap npc2("farmer npc");
	FragTrap npc3("librarian npc");


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
		npc2.takeDamage(20);
	npc2.takeDamage(20);
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
	


}