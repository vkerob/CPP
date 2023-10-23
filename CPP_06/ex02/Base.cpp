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

Base * 	Base::generate(void)
{
	static int 	nb_rand = 0;
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

void	Base::identify(Base* p)
{
	A	*a;
	B	*b;
	C	*c;

	a = dynamic_cast<A *>(p);
	b = dynamic_cast<B *>(p);
	c = dynamic_cast<C *>(p);
	if (a != NULL)
		std::cout << "type is A" << std::endl;
	if (b != NULL)
		std::cout << "type is B" << std::endl;
	if (c != NULL)
		std::cout << "type is C" << std::endl;
}

void	Base::identify(Base& p)
{
	try
	{
		A	a = dynamic_cast<A &>(p);
		std::cout << "type is A" << std::endl;
	}
	catch(std::exception &bc) { std::cout << "t" << std::endl;}
	try
	{
		B	b = dynamic_cast<B &>(p);
		std::cout << "type is B" << std::endl;
	}
	catch(std::exception &bc) {std::cout << "t" << std::endl;}
	try
	{
		C	c = dynamic_cast<C &>(p);
		std::cout << "type is C" << std::endl;
	}
	catch(std::exception &bc) {std::cout << "t" << std::endl;}

}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */