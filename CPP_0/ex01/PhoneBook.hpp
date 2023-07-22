#include"Contact.hpp"
#include<string>

class PhoneBook
{
private:
	Contact	contact[8];
public:
	PhoneBook();
	void		ADD(std::string str);
	std::string	SEARCH();
	void		EXIT();
	~PhoneBook();
};

PhoneBook::PhoneBook()
{

};

PhoneBook::~PhoneBook()
{
	delete this->contact;
};

void	PhoneBook::ADD(std::string str)
{
	this->contact[]
};

std::string	PhoneBook::SEARCH()
{

};

void	PhoneBook::EXIT()
{

};