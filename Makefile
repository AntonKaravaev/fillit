NAME = fillit

SRCS = *.c

OBJ = *.o

INC = includes/

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) :
	@make -C libft
	@gcc $(FLAGS) -c $(SRCS) -I ./libft
	@gcc $(OBJ) -L libft/ -lft -o $(NAME)

clean:
	@make -C libft/ clean
	@rm -f $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all
