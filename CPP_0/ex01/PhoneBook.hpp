#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include"Contact.hpp"

class PhoneBook {

public:

	PhoneBook(void);
	~PhoneBook(void);

	void	add_contact(std::string str, int i);
	

private:
	Contact contact[8];
};


#endif