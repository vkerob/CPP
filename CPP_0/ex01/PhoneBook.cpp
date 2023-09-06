#include"PhoneBook.hpp"

PhoneBook::PhoneBook(void) {

	return ;
}

PhoneBook::~PhoneBook(void) {

	return ;
}

void	PhoneBook::add_contact(std::string str)
{
	contact[0].set_string(str);
}