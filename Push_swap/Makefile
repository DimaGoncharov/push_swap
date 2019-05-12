NAME = checker

LIBRARY = libftprintf.a
SRC = push_swap/*.c
OBJS = *.o

all: $(NAME)

$(NAME):
	make re -C ./libft
	gcc -c -Wall -Wextra -Werror $(SRC) -I.
	gcc -Wall -Wextra -Werror $(OBJS) -L. libft/$(LIBRARY) -o $(NAME)
	make fclean -C ./libft
		
clean:
	rm -f $(OBJS)

fclean:	clean
		rm -f $(NAME)

re:	fclean all
