#include "Serializer.hpp"
#include "Data.hpp"


int	main()
{
	Data		data;
	Data		*ptr1;
	uintptr_t	raw;

	std::cout << data.getName() << std::endl;
	std::cout << &data << std::endl;
	raw = Serializer::serialize(&data);
	std::cout << raw << std::endl;
	ptr1 = Serializer::deserialize(raw);
	if (ptr1 != NULL)
		std::cout << ptr1->getName() << std::endl;
	std::cout << ptr1 << std::endl;
}