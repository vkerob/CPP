#include"PhoneBook.hpp"

PhoneBook::PhoneBook(void) {

	return ;
}

PhoneBook::~PhoneBook(void) {

	return ;
}

void	PhoneBook::add_contact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret, int i)
{
	contact[i].set_first_name(first_name);
	contact[i].set_last_name(last_name);
	contact[i].set_nickname(nickname);
	contact[i].set_phone_number(phone_number);
	contact[i].set_darkest_secret(darkest_secret);


}