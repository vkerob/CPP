#ifndef CONTACT_HPP
# define CONTACT_HPP

#include<iostream>
#include<string>

class Contact {

public:

	Contact(void);
	~Contact(void);
	void		set_string(std::string str, std::string identifier);
	std::string	get_string(std::string identifier);

private:
	std::string	first_name;
	std::string last_name;
	std::string nickname;
	std::string	phone_number;
	std::string	darkest_secret;
};

#endif