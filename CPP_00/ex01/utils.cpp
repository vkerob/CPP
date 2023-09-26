#include"Contact.hpp"
#include"PhoneBook.hpp"
#include<cstdlib>

int	check_only_digit(std::string number)
{
	int i = 0;
	if (number.empty())
		return (1);
	while (number[i])
	{
		if (isdigit(number[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	check_index(std::string number)
{
	int i = 0;
	if (number.empty())
		return (1);
	while (number[i])
	{
		if (isdigit(number[i]) == 0 || number.length() > 1 || number[i] > '7')
			return (1);
		i++;
	}
	return (0);
}

int	stack_input_and_check_empty(std::string &str, std::string entry)
{
	if (entry == "phone number: ")
	{
		std::cout << entry;
		if (!std::getline(std::cin, str))
		{
			std::cout << std::endl;
			return (1);
		}
		while (check_only_digit(str))
		{
			if (!str.empty())
				std::cout << "Digit only for phone number" << std::endl;
			std::cout << entry;
			if (!std::getline(std::cin, str))
			{
				std::cout << std::endl;
				return (1);
			}
		}
		return (0);
	}
	if (entry == "index: ")
	{
		std::cout << entry;
		if (!std::getline(std::cin, str))
		{
			std::cout << std::endl;
			return (1);
		}
		while (check_index(str))
		{
			if (!str.empty())
				std::cout << "Number only for index: 0-7" << std::endl;
			std::cout << entry;
			if (!std::getline(std::cin, str))
			{
				std::cout << std::endl;
				return (1);
			}
		}
		return (0);
	}
	while (str.empty())
	{
		std::cout << entry;
		if (!std::getline(std::cin, str))
		{
			std::cout << std::endl;
			return (1);
		}
	}
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
	if (stack_input_and_check_empty(darkest_secret, "darkest secret: "))
		return (1);
	phonebook.add_contact(first_name, last_name, nickname, phone_number, darkest_secret, i);
	return (0);
}
