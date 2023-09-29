#include"Animal.hpp"
#include"Cat.hpp"
#include"Dog.hpp"
#include"WrongAnimal.hpp"
#include"WrongCat.hpp"

int main()
{
	
	/*Animal *array[10];

	Animal *dog = new Dog();
	Animal *cat = new Cat();

	std::cout << std::endl;
	((Dog *)dog)->setBrainString("test", 0);
	std::cout << ((Dog *)dog)->getBrainString(0) << std::endl;
	std::cout << std::endl;
	//dog = cat;
	for(int i = 0; i < 5; i++)
		array[i] = new Dog();
	std::cout << std::endl;
	for(int i = 5; i < 10; i++)
		array[i] = new Cat();
	std::cout << std::endl;
	for(int i = 0; i < 10; i++)
		delete array[i];
	
	delete dog;
	delete cat;*/

	Cat *cat1 = new Cat();
	(cat1)->setBrainString("cat1", 0);
	std::cout << (cat1)->getBrainString(0) << std::endl;
	Cat	*cat2 = new Cat(*cat1);
	delete cat1;

	std::cout << (cat2)->getBrainString(0) << std::endl;
	delete cat2;
	std::cout << std::endl;
	return 0;

}