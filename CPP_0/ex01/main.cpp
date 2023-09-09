#include"Contact.hpp"
#include"PhoneBook.hpp"
#include"utils.hpp"
#include<cstdlib>

int	main(void)
{
	PhoneBook	phonebook;
	std::string	input;
	int i;

	i = 0;
	while(1)
	{
		i %= 8;
		if (stack_input_and_check_empty(input, "PhoneBook : "))
			return (0);
		if (input == "EXIT")
			return(0);
		else if (input == "SEARCH")
		{
			phonebook.print_info(phonebook);
			if (phonebook.get_index(phonebook))
				return (0);
		}
		else if (input == "ADD")
		{
			if (stack_all_info_and_add_contact(phonebook, i))
				return (0);
		}
		else
		{
			std::cout << "posible input: " << std::endl << "ADD, SEARCH, EXIT" << std::endl;
		}
		input.clear();
	}
}