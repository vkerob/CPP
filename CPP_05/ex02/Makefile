NAME = ex02

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -g -Wno-shadow

SRC = main.cpp \
		Bureaucrat.cpp \
		AForm.cpp \
		ShrubberyCreationForm.cpp \
		RobotomyRequestForm.cpp \
		PresidentialPardonForm.cpp \


OBJ = $(SRC:.cpp=.o)

%.o : %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $(<:.cpp=.o)

$(NAME) : $(OBJ)
	@$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

all : $(NAME)

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re