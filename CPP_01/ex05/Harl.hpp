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

	public:

		void complain( std::string level );
		Harl();
		~Harl();
};


#endif