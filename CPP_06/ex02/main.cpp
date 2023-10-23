# include "Base.hpp"

int	main(void)
{
	Base	A;
	Base	*base1;
	Base	*base2;


	base1 = A.generate();
	base2 = A.generate();
	base1->identify(base1);
	base2->identify(base2);
	delete (base1);
	delete (base2);


}