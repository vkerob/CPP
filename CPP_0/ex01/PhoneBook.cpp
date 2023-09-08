#include"PhoneBook.hpp"

PhoneBook::PhoneBook(void) {

	return ;
}

PhoneBook::~PhoneBook(void) {

	return ;
}

int	PhoneBook::add_contact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret, int i)
{
	if (contact[i].set_phone_number(phone_number))
		return (1);
	contact[i].set_string(first_name, "first_name");
	contact[i].set_string(last_name, "last_name");
	contact[i].set_string(nickname, "nickname");
	contact[i].set_string(darkest_secret, "darkest_secret");


}