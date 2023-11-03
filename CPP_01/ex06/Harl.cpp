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

int	_str_to_enum(std::string level)
{
	int i = 0;
	const char *tab[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for(;i<4; i++)
	{
		if (level == tab[i])
			return (i);
	}
	std::cout << "Probably complaining about insignificant problems" << std::endl;
	return (i++);
}

void	Harl::_debug( void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
	_info();
}

void	Harl::_info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
	_warning();
}

void	Harl::_warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
	_error();
}

void	Harl::_error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain( std::string level )
{
	int enum_level;

	enum_level = _str_to_enum(level);
	switch(enum_level)
	{
		case debug_level:
			(this->*_tab_funcptr[0])();
			break;
		case info_level:
			(this->*_tab_funcptr[1])();
			break;
		case warning_level:
			(this->*_tab_funcptr[2])();
			break;
		case error_level:
			(this->*_tab_funcptr[3])();
			break;
		case 4:
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}

}