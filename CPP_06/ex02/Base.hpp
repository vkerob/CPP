#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <time.h>



class Base
{

	public:

		Base();
		virtual ~Base();


		Base * 	generate(void) const;
		void	identify(Base* p) const;
		void	identify(Base& p) const;

};

//std::ostream &			operator<<( std::ostream & o, Base const & i );

#endif /* ************************************************************ BASE_H */