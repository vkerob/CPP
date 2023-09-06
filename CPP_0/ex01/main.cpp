#include"Contact.hpp"
#include"PhoneBook.hpp"

int	main(void)
{
	PhoneBook	directory;
	std::string	input;

	while(1)
	{
		std::cout << "PhoneBook : " << std::endl;
		std::cin >> input;
		if (input[0] == '\0')

		else if (strcmp(input, "EXIT"))

		else if (strcmp(input, "SEARCH"))

		else if (strcmp(input, "ADD"))
		{
			directory.add_contact(std:cin);
		}
		else
	}
}