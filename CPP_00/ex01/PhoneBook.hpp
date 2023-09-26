#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include"Contact.hpp"

class PhoneBook {

	private:

		std::string	_fill_string(PhoneBook &phonebook, std::string identifier, int i);
		Contact 	_contact[8];

	public:

		PhoneBook(void);
		~PhoneBook(void);
		int			add_contact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret, int &i);
		void		print_info(PhoneBook &phonebook);
		int			get_index(PhoneBook &phonebook);

};


#endif