#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define BUFF_SIZE 1024
# include <unistd.h>
# include "libft/libft/libft.h"

typedef struct	s_push
{
	int			vis;
	int			i;
	long		*stack_a;
	long		*stack_b;
	int			size_a;
	int			size_b;
	int			max;
	int			min;
	int			res;
	int			index;
	int			fl;
}				t_push;

typedef struct	s_swap
{
	int			pa;
	int			pb;
	int			ra;
	int			rb;
	int			rr;
	int			rra;
	int			rrb;
	int			rrr;
}                 t_swap;
 
int				ft_max(t_push *push);
int				ft_min(t_push *push);
int				checker(t_push *push);

void			ft_inicialization_push(t_push *push);
void			ft_initialization_swap(t_swap *swap);
void			ft_out(void);
void			ft_record(t_push *push, char *argv);
void			printstack(t_push *push);

void			ft_count_digits(char *av, t_push *push);
int				ft_check_repeat(t_push	*push);
void			ft_valid(char *av, t_push *push);
int				ft_skip_null_znak(char *argv);
int				ft_check_overflow(t_push *push, char *argv, int num);

void			ft_do_rotate(t_push *push, t_swap *swap);
void			ft_do_reverse_rotate(t_push *push, t_swap *swap);
void			ft_sort_stack(t_push *push, t_swap *swap);
void			ft_stack_balance(t_push *push);

int				ft_check_cyclic_sort(t_push *push);
void			ft_do_separate(t_push *push);
void			ft_separate_stack(t_push *push);
int				ft_check_sort_elements(t_push *push);

void			ft_analyze_operation(t_swap *swap);
void			ft_write_index_res(t_push *push, t_swap *swap, int i);
void			ft_counter(t_push *push, t_swap *swap, int i);
void			ft_count_operation(t_push *push);
void			ft_sort_three_item(t_push *push);

void			ft_swap(long *a, long *b);
void			swap_operations(t_push	*pu, char letter);
void			ft_do_rra(t_push *push, int *i);
void			reverse_rotate_operations(t_push	*pu, char letter);

void			push_operations(t_push	*pu, char letter);
void			rotate_operations(t_push	*pu, char letter);
void			ft_do_pa(t_push *push, int *i);
void			ft_do_pb(t_push *push, int *i);

void			doop(t_push *push, char **oper, int i);
void			read_input(t_push *push);
void			ft_valid_buf(char **buff);

void			ft_do_count(t_push *push);
void			ft_memory(t_push *push);
#endif