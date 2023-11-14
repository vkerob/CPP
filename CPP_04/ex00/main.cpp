#include"Animal.hpp"
#include"Cat.hpp"
#include"Dog.hpp"
#include"WrongAnimal.hpp"
#include"WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	const WrongAnimal* wrongmeta = new WrongAnimal();
	const WrongAnimal* wrongi = new WrongCat();

	std::cout << "TYPE:" << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	std::cout << std::endl << "SOUND:" << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout << std::endl << "WRONGANIMAL:" << std::endl;
	wrongmeta->makeSound();
	wrongi->makeSound();
	
	std::cout << wrongmeta->getType() << std::endl;
	std::cout << wrongi->getType() << std::endl;

	std::cout << *wrongmeta << std::endl;

	delete meta;
	delete i;
	delete j;
	delete wrongmeta;
	delete wrongi;
	return 0;
}