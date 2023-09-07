#include"Contact.hpp"
#include"PhoneBook.hpp"


void	stack_input_and_check_empty(std::string &str)
{
	std::cin >> str;
	if (str.empty())
		exit(0);
}

void	stack_all_info(PhoneBook &phonebook, int i)
{
	std::string	first_name, last_name, nickname, phone_number, darkest_secret;

	phonebook.add_contact(first_name, last_name, nickname, phone_number, darkest_secret, i);
}

int	main(void)
{
	PhoneBook	phonebook;
	std::string	input;
	int i;

	i = 0;
	while(1)
	{
		std::cout << "PhoneBook : " << std::endl;
		stack_input_and_check_empty(input);
		if (input == "EXIT")
			return(0);
		//else if (input == "SEARCH")
		else if (input == "ADD")
		{
			stack_all_info(phonebook, i);
		}
		else
		{
			std::cout << "posible input: " << std::endl << "ADD, SEARCH, EXIT" << std::endl;
		}
	}
}