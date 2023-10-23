#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <string>
# include <cstdlib>



class Base
{

	public:

		Base();
		virtual ~Base();


		Base * 	generate(void);
		void	identify(Base* p);
		void	identify(Base& p);


	private:

};

//std::ostream &			operator<<( std::ostream & o, Base const & i );

#endif /* ************************************************************ BASE_H */