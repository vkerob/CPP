NAME = harlFilter

CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98 -g

SRC = main.cpp \
		Fixed.cpp \

OBJ = $(SRC:.cpp=.o)

%.o : %.cpp
	@$(CC) $(CFLAGS) -c $< -o $(<:.cpp=.o)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)

all : $(NAME)

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re