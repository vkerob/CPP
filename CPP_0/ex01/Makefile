NAME = PhoneBook

CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = main.cpp \
		Contact.cpp \
		PhoneBook.cpp \

OBJ = $(SRC:.c=.o)

%.o : %.cpp
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME) : $(OBJ)

	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)

all : $(NAME)

clean :
	@make clean
	@rm -f $(OBJ)

fclean : clean
	@make fclean
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
