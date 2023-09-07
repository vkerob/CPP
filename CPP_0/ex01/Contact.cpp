
#include"Contact.hpp"

Contact::Contact(void) {

	return ;

}

Contact::~Contact(void) {

	return ;
}

void	Contact::set_string(std::string str, std::string identifier)
{
	if (str.length() > 9)
	{
		str = str.substr(0, 9);
		str.append(".");
	}
	if (identifier == "first_name")
		this->first_name = str;
	else if (identifier == "last_name")
		this->last_name = str;
	else if (identifier == "nickname")
		this->nickname = str;
	else if (identifier == "darkest_secret")
		this->darkest_secret = str;
}


int	Contact::set_phone_number(std::string number)
{
	int i = 0;
	while (number[i])
	{
		if (isdigit(number[i]) != 1)
			return (1);
		i++;
	}
	if (number.length() > 9)
	{
		number = number.substr(0, 9);
		number.append(".");
	}
	this->phone_number = number ;
	return (0);
}