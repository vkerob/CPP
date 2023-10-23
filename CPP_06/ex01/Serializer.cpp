#include "Serializer.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Serializer::Serializer()
{
}

Serializer::Serializer( const Serializer & src )
{
	(void)src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Serializer::~Serializer()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Serializer &				Serializer::operator=( Serializer const & rhs )
{
	(void)rhs;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/
uintptr_t	Serializer::serialize(Data* ptr)
{
	if (ptr != NULL)
	{
		uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
		return (raw);
	}
	return (0);
}
	
Data*		Serializer::deserialize(uintptr_t raw)
{
	if (raw == 0)
		return (NULL);
	Data *ptr = reinterpret_cast<Data *>(raw);
	return (ptr);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */