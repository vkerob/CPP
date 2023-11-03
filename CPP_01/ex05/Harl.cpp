#include"Harl.hpp"


Harl::Harl()
{
	_tab_funcptr[0] = &Harl::_debug;
	_tab_funcptr[1] = &Harl::_info;
	_tab_funcptr[2] = &Harl::_warning;
	_tab_funcptr[3] = &Harl::_error;
}

Harl::~Harl()
{

}

void	Harl::_debug( void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::_info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::_warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::_error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain( std::string level )
{
	const char *tab_str[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for(int i = 0; i<4; i++)
	{
		if (level == tab_str[i])
		{
			(this->*_tab_funcptr[i])();
			return ;
		}
		if (i == 3)
			std::cout << "Probably complaining about insignificant problems" << std::endl;
	}
}