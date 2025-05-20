NAME = minishell

SRC = 	buildins.c\
		environ.c\
		execute.c\
		helpers.c\
		main.c\
		
OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra -lreadline
CC	= gcc

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean : 
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all




