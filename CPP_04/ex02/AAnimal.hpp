#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>

class AAnimal
{

	protected:

		std::string _type;

	public:

		AAnimal();
		AAnimal( AAnimal const & src );
		virtual ~AAnimal();


		AAnimal &		operator=( AAnimal const & rhs );


		virtual void	makeSound(void) const = 0;

		
		void	setType(std::string str);
		std::string getType(void) const;




};

std::ostream &			operator<<( std::ostream & o, AAnimal const & i );

#endif /* ********************************************************** ANIMAL_H */