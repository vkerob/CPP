#include"ClapTrap.hpp"

void	displayInfo(ClapTrap &clap)
{
	std::cout << std::endl;
	std::cout << "name: " << clap.getName() << std::endl;
	std::cout << "hit points: " << clap.getHitPoint() << std::endl;
	std::cout << "energy point: " << clap.getEnergyPoint() << std::endl;
	std::cout << "attack damage: " << clap.getAttackDamage() << std::endl;
}


int	main(void)
{
	ClapTrap npc1("gunsmith npc");
	ClapTrap npc2("farmer npc");
	ClapTrap npc3("librarian npc");


//---------------gunsmith npc---------------//
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
		npc2.takeDamage(5);
	npc2.takeDamage(5);
	displayInfo(npc2);



//---------------librarian npc---------------//
	std::cout << "\033[94m//---------------librarian npc---------------//\033[0m" <<std::endl;
	displayInfo(npc3);
	while (npc3.getEnergyPoint() > 0)
		npc3.beRepaired(4294967295);
	npc3.beRepaired(5);
	displayInfo(npc3);
	


}