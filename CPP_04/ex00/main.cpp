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


	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;


	j->makeSound();
	i->makeSound(); //will output the cat sound!
	meta->makeSound();

	wrongmeta->makeSound();
	wrongi->makeSound();


	delete meta;
	delete i;
	delete j;
	delete wrongmeta;
	delete wrongi;
	return 0;
}