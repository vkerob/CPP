#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include"Contact.hpp"

class PhoneBook {

public:

	PhoneBook(void);
	~PhoneBook(void);
	void	PhoneBook::add_contact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret, int i);

private:
	Contact contact[8];
};


#endif