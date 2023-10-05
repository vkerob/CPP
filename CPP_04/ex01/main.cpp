#include"Animal.hpp"
#include"Cat.hpp"
#include"Dog.hpp"
#include"WrongAnimal.hpp"
#include"WrongCat.hpp"

int main()
{
	
/*-----------------------------------Test polymorphisme------------------------------------*/
	
	
	Animal *array[10];

	Animal *dog = new Dog();
	Animal *cat = new Cat();

	std::cout << std::endl;
	((Dog *)dog)->setBrainString("test", 0);
	std::cout << ((Dog *)dog)->getBrainString(0) << std::endl;
	std::cout << std::endl;
	for(int i = 0; i < 5; i++)
		array[i] = new Dog();
	std::cout << std::endl;
	for(int i = 5; i < 10; i++)
		array[i] = new Cat();
	std::cout << std::endl;
	for(int i = 0; i < 10; i++)
		delete array[i];
	
	delete dog;
	delete cat;


/*-----------------------------------Test copy construteur/ operateur=------------------------------------*/
	
	
	Cat *cat1 = new Cat();
	cat1->setBrainString("cat1", 0);
	cat1->setBrainString("cat1", -5);
	cat1->setBrainString("cat1", 150);
	cat1->makeSound();
	for (int i = 0; i < 100; i++){
		cat1->setBrainString("cat1", i);
	}
	std::cout << std::endl;
	std::cout << "string at index 0 of cat1: " << cat1->getBrainString(0) << std::endl;
	std::cout << std::endl;
	Cat	*cat2 = new Cat(*cat1);
	

	delete cat1;
	cat2->makeSound();
	std::cout << std::endl;
	std::cout << "string at index 0 of cat2: " << cat2->getBrainString(0) << std::endl;
	std::cout << std::endl;
	for (int i = -2; i < 102; i++){
		std::cout << "string at index " << i << " of cat2: " << cat2->getBrainString(i) << std::endl;
	}
	delete cat2;


/*-----------------------------------Test copy operateur=------------------------------------*/


	Cat tmp;

	tmp.setBrainString("cat3", 0);

	Animal *cat3 = &tmp;
	Animal *cat4 = cat3;

	std::cout << std::endl;
	std::cout << ((Cat *)cat4)->getBrainString(0) << std::endl;
	std::cout << std::endl;


/*-----------------------------------Test WrongCat/WrongAnimal------------------------------------*/
	

	/*WrongCat *wrongCat1 = new WrongCat();
	wrongCat1->setBrainString("wrongCat1", 0);
	wrongCat1->setBrainString("wrongCat1", -5);
	wrongCat1->setBrainString("wrongCat1", 150);
	for (int i = 0; i < 100; i++){
		wrongCat1->setBrainString("cat1", i);
	}
	std::cout << std::endl;
	std::cout << "string at index 0 of wrongCat1: " << wrongCat1->getBrainString(0) << std::endl;
	std::cout << std::endl;
	WrongCat *wrongCat2 = new WrongCat(*wrongCat1); 

	//delete wrongCat1;
	wrongCat2->makeSound();
	std::cout << std::endl;
	for (int i = -2; i < 102; i++){
		std::cout << "string at index " << i << " of wrongCat2: " << wrongCat2->getBrainString(i) << std::endl;
	}
	std::cout << std::endl;
	delete wrongCat2;*/


}