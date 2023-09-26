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
		this->first_name = str;
	else if (identifier == "last_name")
		this->last_name = str;
	else if (identifier == "nickname")
		this->nickname = str;
	else if (identifier == "phone_number")
		this->phone_number = str;
	else if (identifier == "darkest_secret")
		this->darkest_secret = str;
}

std::string Contact::get_string(std::string identifier)
{
	if (identifier == "first_name")
		return(this->first_name);
	else if (identifier == "last_name")
		return(this->last_name);
	else if (identifier == "nickname")
		return(this->nickname);
	else if (identifier == "phone_number")
		return(this->phone_number);
	else if (identifier == "darkest_secret")
		return(this->darkest_secret);
	return ("");
}