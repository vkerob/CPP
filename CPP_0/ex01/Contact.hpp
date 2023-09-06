#ifndef CONTACT_H
# define CONTACT_H

#include<iostream>
#include<string>

class Contact {

public:

	Contact(void);
	~Contact(void);
	void	set_string(std::string str);
	void	set_phone_number(std::string number);

private:
	std::string	first_name;
	std::string last_name;
	std::string nickname;
	std::string	phone_number;
	std::string	darkest_secret;
};

#endif