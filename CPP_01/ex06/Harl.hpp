#ifndef HARL_CPP
#define HARL_CPP

#include<iostream>

class Harl
{
	private:
		
		void	_debug( void );
		void	_info( void );
		void	_warning( void );
		void	_error( void );
		void	(Harl::*_tab_funcptr[4])(void);
		enum 	Level {debug_level, info_level, warning_level, error_level, none_level};
		Level	_str_to_enum(std::string level);

	public:

		void complain( std::string level );
		Harl();
		~Harl();
};

#endif