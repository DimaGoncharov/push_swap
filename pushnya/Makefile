NAME_PUSH = push_swap

NAME_CH = checker

SRC_CH = main_for_checker.c \
		ft_min_max.c \
		ft_checker.c \
		operations1.c \
		operations2.c \
		inicialization.c \
		validation.c \
		sort.c \
		ft_check_cyclic_sort.c \
		counting.c \
		ft_memory.c \
		
SRC_PUSH = main.c \
		ft_min_max.c \
		ft_checker.c \
		operations1.c \
		operations2.c \
		inicialization.c \
		validation.c \
		sort.c \
		ft_check_cyclic_sort.c \
		counting.c \
		ft_memory.c \
		
OBJS = *.o
INCLUDES = libft/libftprintf.a

all: $(NAME_PUSH) $(NAME_CH)

$(NAME_PUSH): $(SRC_PUSH)
		make -C libft
		gcc -Wall -Werror -Wextra $(SRC_PUSH) $(INCLUDES) -o $(NAME_PUSH)

$(NAME_CH): $(SRC_CH)
		gcc -Wall -Werror -Wextra $(SRC_CH) $(INCLUDES) -o $(NAME_CH)

clean: 
		make clean -C libft

fclean: clean
		make fclean -C libft
		rm -f $(NAME_PUSH)
		rm -f $(NAME_CH)

re: fclean all