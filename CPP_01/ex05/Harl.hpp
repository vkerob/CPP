
#include<iostream>

class Harl
{
	private:
		
		void	error( void );
		void	info( void );
		void	warning( void );
		void	error( void );

	public:

		void complain( std::string level );
		Harl();
		~Harl();
};


