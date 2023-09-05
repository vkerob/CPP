#ifndef CONTACT_H
# define CONTACT_H

#include<iostream>

class Contact {

public:

	Contact(void);
	~Contact(void);
	void	set_first_name(std::string);

private:
	std::string	first_name;
	std::string last_name;
	std::string nickname;
	std::string	phone_number;
	std::string	darkest_secret;
};

#endif