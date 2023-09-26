#include"Contact.hpp"

Contact::Contact(void) {

	return ;

}

Contact::~Contact(void) {

	return ;
}

void	Contact::set_string(std::string str, std::string identifier)
{
	if (identifier == "first_name")
		this->_first_name = str;
	else if (identifier == "last_name")
		this->_last_name = str;
	else if (identifier == "nickname")
		this->_nickname = str;
	else if (identifier == "phone_number")
		this->_phone_number = str;
	else if (identifier == "darkest_secret")
		this->_darkest_secret = str;
}

std::string Contact::get_string(std::string identifier)
{
	if (identifier == "first_name")
		return(this->_first_name);
	else if (identifier == "last_name")
		return(this->_last_name);
	else if (identifier == "nickname")
		return(this->_nickname);
	else if (identifier == "phone_number")
		return(this->_phone_number);
	else if (identifier == "darkest_secret")
		return(this->_darkest_secret);
	return ("");
}