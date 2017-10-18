/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohesheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 18:19:43 by ohesheli          #+#    #+#             */
/*   Updated: 2017/03/15 18:44:16 by ohesheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"

typedef struct	s_stack
{
	struct s_stack	*next;
	int				n;
}				t_stack;

typedef struct	s_command
{
	struct s_command	*next;
	char				*str;
	struct s_command	*prev;
}				t_command;

typedef struct	s_size
{
	int sorted[2];
	int unsorted[2];
	int pivot;
}				t_size;

int				g_c;

void			free_commands(t_command *begin);
void			rrb(t_stack **a, t_command **command);
void			rb(t_stack **a, t_command **command);
void			pb(t_stack **a, t_stack **b, t_command **command);
void			ra(t_stack **a, t_command **command);
void			pa(t_stack **a, t_stack **b, t_command **command);
void			rra(t_stack **a, t_command **command);
void			sa(t_stack **a, t_command **command);
void			sb(t_stack **a, t_command **command);
t_stack			*push(t_stack **head, t_stack *elem);
t_stack			*pop(t_stack **head);
t_stack			*create_elem(int n);
int				count_commands(t_command *commands);
int				init_sort(t_stack **a, t_stack **b, t_command **crawler,\
				t_command *begin);
void			make_sort(t_stack **a, t_stack **b, t_command **crawler,\
				t_command *begin);
void			alt_sort(t_stack **a, t_stack **b, int size, t_command **last);
void			alt_rev_sort(t_stack **a, t_stack **b, int size,\
				t_command **last);
void			operate_stacks2(char *str, t_stack **a, t_stack **b, int v);
void			operate_stacks3(char *str, t_stack **a, t_stack **b, int v);
void			operate_stacks4(char *str, t_stack **a, t_stack **b, int v);
int				handle_args(int argc, char **argv, t_stack **stack, int *v);
long			ft_atol(char const *str);
void			sort_little_all(t_stack **a, t_command **last);
void			rev_sort_little_all(t_stack **a, t_command **last);
void			swap(t_stack **a);
void			op_push(t_stack **a, t_stack **b);
void			rotate(t_stack **a);
void			rrotate(t_stack **a);
void			operate_stacks(char *str, t_stack **a, t_stack **b, int v);
int				check_sort(t_stack *a);
void			free_stacks(t_stack **a, t_stack **b);
int				check_equal(t_stack *stack, int len);
int				check_symbols(char *str);
int				count_stack(t_stack *stack, t_stack *end);
int				find_pivot(t_stack *a, int size, int *r);
void			sort(t_stack **a, t_stack **b, int size, t_command **last);
void			rev_sort(t_stack **a, t_stack **b, int size, t_command **last);
void			sort_little(t_stack **a, t_stack **b, int size,\
				t_command **last);
void			rev_sort_little(t_stack **a, t_stack **b, int size,\
				t_command **last);
void			swap_nodes(t_stack **a, t_stack **b);
void			push_command(t_command **last, t_command *node);
t_command		*create_command(char *str);
void			print_commands(t_command *node);
void			check_last(t_stack **a, t_command **last);
void			optimize_commands(t_command **begin);
int				is_useless(t_command *node);
void			delete_command(t_command *node);
void			check_first(t_stack **a, t_command **commands);
int				need_for_push(t_stack **a, int size, int pivot);
int				need_for_rev_push(t_stack **a, int size, int pivot);
void			ft_qsort(int *arr, int start, int end);
void			swaper(int *i, int *j);
int				alt_find_pivot(int *arr, int start, int end);
void			visualize(t_stack *a, t_stack *b);

#endif
