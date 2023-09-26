#include"PhoneBook.hpp"
#include"utils.hpp"

PhoneBook::PhoneBook(void) {

	std::cout << "create your own phonebook !" << std::endl;
	return ;
}

PhoneBook::~PhoneBook(void) {

	std::cout << "finish !" << std::endl;
	return ;
}

int	PhoneBook::add_contact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret, int &i)
{
	this->_contact[i].set_string(first_name, "first_name");
	this->_contact[i].set_string(last_name, "last_name");
	this->_contact[i].set_string(nickname, "nickname");
	this->_contact[i].set_string(phone_number, "phone_number");
	this->_contact[i].set_string(darkest_secret, "darkest_secret");
	i++;
	return (0);
}

void	PhoneBook::print_info(PhoneBook &phonebook)
{
	int	i = 0;
	std:: string str;

	if (!this->_contact[i].get_string("first_name").empty())
		std::cout << "   index  |first name| last name| nickname |" << std::endl;
	else
	{
		std::cout << this->_contact[i].get_string("first_name") << std::endl;
		std::cout << "Add a contact before searching" << std::endl;
	}
	while (!this->_contact[i].get_string("first_name").empty())
	{
		std::cout << "         " << i << "|";
		std::cout << _fill_string(phonebook, "first_name", i);
		std::cout << _fill_string(phonebook, "last_name", i);
		std::cout << _fill_string(phonebook, "nickname", i) << std::endl;
		i++;
		if (i == 8)
			break ;
	}
	std::cout << std::endl;
}

int	PhoneBook::get_index(PhoneBook &phonebook)
{
	std::string	str;
	int			index;

	if (this->_contact[0].get_string("first_name") == "")
		return (0);
	if (stack_input_and_check_empty(str, "index: "))
		return (1);
	index = str[0] - 48;
	if (this->_contact[index].get_string("first_name") == "")
	{
		std::cout << "This contact does not exit" << std::endl;
		return (0);
	}
	std::cout << "first name| last name|  nickname|     phone|    secret|" << std::endl;
	std::cout << _fill_string(phonebook, "first_name", index);
	std::cout << _fill_string(phonebook, "last_name", index);
	std::cout << _fill_string(phonebook, "nickname", index);
	std::cout << _fill_string(phonebook, "phone_number", index);
	std::cout << _fill_string(phonebook, "darkest_secret", index) << std::endl << std::endl;
	return (0);

}

std::string PhoneBook::_fill_string(PhoneBook &phonebook, std::string identifier, int i)
{
	std::string str;
	if (identifier == "first_name")
		str = phonebook._contact[i].get_string("first_name");
	if (identifier == "last_name")
		str = phonebook._contact[i].get_string("last_name");
	if (identifier == "nickname")
		str = phonebook._contact[i].get_string("nickname");
	if (identifier == "phone_number")
		str = phonebook._contact[i].get_string("phone_number");
	if (identifier == "darkest_secret")
		str = phonebook._contact[i].get_string("darkest_secret");
	if (str.length() > 9)
	{
		str = str.substr(0, 9);
		str.append(".");
	}
	while (str.length() < 10)
		str = " " + str;
	str.append("|");
	return (str);
}
