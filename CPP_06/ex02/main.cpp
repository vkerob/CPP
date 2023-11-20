# include "Base.hpp"

int	main(void)
{
	Base	A;
	Base	*base1;


	base1 = A.generate();
	base1->identify(base1);
	std::cout << std::endl;
	base1->identify(*base1);
	delete (base1);


}