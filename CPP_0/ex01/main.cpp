#include"Contact.hpp"
#include"PhoneBook.hpp"
#include<cstdlib>

int	stack_input_and_check_empty(std::string &str, std::string entry)
{
	std::cout << entry;
	std::getline(std::cin, str);
	if (str.empty())
		return (1);
	if (str == "\n")
		stack_input_and_check_empty(str, entry);
	return (0);
}

int	stack_all_info_and_add_contact(PhoneBook &phonebook, int &i)
{
	std::string	first_name, last_name, nickname, phone_number, darkest_secret;
	if (stack_input_and_check_empty(first_name, "first name: "))
		return (1);
	if (stack_input_and_check_empty(last_name, "last name: "))
		return (1);
	if (stack_input_and_check_empty(nickname, "nickname: "))
		return (1);
	if (stack_input_and_check_empty(phone_number, "phone number: "))
		return (1);
	if (stack_input_and_check_empty(darkest_secret, "darknest secret: "))
		return (1);
	i++;
	phonebook.add_contact(first_name, last_name, nickname, phone_number, darkest_secret, i);
	return (0);
}

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