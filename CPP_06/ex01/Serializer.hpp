#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>
# include <stdint.h>
# include "Data.hpp"

class Serializer
{

	private:

		Serializer &		operator=( Serializer const & rhs );

	public:

		Serializer();
		Serializer( Serializer const & src );
		~Serializer();


		uintptr_t	serialize(Data* ptr);
		Data*		deserialize(uintptr_t raw);
};

//std::ostream &			operator<<( std::ostream & o, Serializer const & i );

#endif /* ****************************************************** SERIALIZER_H */