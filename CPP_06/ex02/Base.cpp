#include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Base::Base()
{
}



/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Base::~Base()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/


/*
** --------------------------------- METHODS ----------------------------------
*/

Base * 	Base::generate(void) const
{
	srand(time(NULL));
	int 		nb_rand = rand() % 3;
	Base		*ABC;

	if (nb_rand == 0)
		ABC = new A();
	else if (nb_rand == 1)
		ABC = new B();
	else
		ABC = new C();
	nb_rand++;
	if (nb_rand == 3)
		nb_rand = 0;
	return (ABC);
}

void	Base::identify(Base* p) const
{
	A	*a;
	B	*b;
	C	*c;

	a = dynamic_cast<A *>(p);
	b = dynamic_cast<B *>(p);
	c = dynamic_cast<C *>(p);
	if (a != NULL)
		std::cout << "type is A" << std::endl;
	else if (b != NULL)
		std::cout << "type is B" << std::endl;
	else if (c != NULL)
		std::cout << "type is C" << std::endl;
}

void	Base::identify(Base& p) const
{
	try
	{
		A	a = dynamic_cast<A &>(p);
		std::cout << "type is A" << std::endl;
	}
	catch(std::exception &bc) { std::cout << "not A" << std::endl;}
	try
	{
		B	b = dynamic_cast<B &>(p);
		std::cout << "type is B" << std::endl;
	}
	catch(std::exception &bc) {std::cout << "not B" << std::endl;}
	try
	{
		C	c = dynamic_cast<C &>(p);
		std::cout << "type is C" << std::endl;
	}
	catch(std::exception &bc) {std::cout << "not C" << std::endl;}

}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */