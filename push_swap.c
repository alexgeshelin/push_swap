/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohesheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 17:23:27 by ohesheli          #+#    #+#             */
/*   Updated: 2017/02/13 17:23:30 by ohesheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_command	*begin;
	t_command	*crawler;
	int			v;

	a = NULL;
	b = NULL;
	if (argc <= 2)
		return (0);
	if (!(handle_args(argc, argv, &a, &v)))
	{
		ft_putstr("Error");
		return (0);
	}
	begin = create_command("begin");
	crawler = begin;
	while (!(check_sort(a)) && init_sort(&a, &b, &crawler, begin))
		handle_args(argc, argv, &a, &v);
	print_commands(begin->next);
	free_commands(begin);
	free_stacks(&a, &b);
	return (0);
}

int		init_sort(t_stack **a, t_stack **b, t_command **crawler,\
t_command *begin)
{
	static int	r = 0;
	int			i;

	if (r > 100)
	{
		free_commands(begin->next);
		make_sort(a, b, &begin, begin);
		return (0);
	}
	make_sort(a, b, crawler, begin);
	if ((i = 0) || (count_commands(begin->next) >= 700))
	{
		while (i++ < r)
		{
			begin = begin->next;
			rotate(a);
		}
		free_commands(begin->next);
		ra(a, &begin);
		*crawler = begin;
		free_stacks(a, b);
		r++;
		return (1);
	}
	return (0);
}

int		count_commands(t_command *commands)
{
	int res;

	res = 1;
	if (!commands)
		return (0);
	while (commands->next)
	{
		res++;
		commands = commands->next;
	}
	return (res);
}

void	alt_sort(t_stack **a, t_stack **b, int size, t_command **last)
{
	int		i;
	int		j;
	int		r;
	int		pivot;

	if (size <= 3 || (i = 0))
	{
		sort_little(a, b, size, last);
		return ;
	}
	pivot = find_pivot(*a, size, &r);
	j = size;
	while (need_for_push(a, j, pivot) && j--)
	{
		if ((*a)->n < pivot && ++i)
			pb(a, b, last);
		else if (++r)
			ra(a, last);
	}
	while (r-- && count_stack(*a, *a) + i != size)
		rra(a, last);
	alt_sort(a, b, size - i, last);
	alt_rev_sort(b, a, i, last);
	while (i--)
		pa(a, b, last);
}

void	alt_rev_sort(t_stack **a, t_stack **b, int size, t_command **last)
{
	int		i;
	int		j;
	int		r;
	int		pivot;

	if (size <= 3 || (i = 0))
	{
		rev_sort_little(a, b, size, last);
		return ;
	}
	pivot = find_pivot(*a, size, &r);
	j = size;
	while (need_for_rev_push(a, j, pivot) && j--)
	{
		if ((*a)->n >= pivot && ++i)
			pa(b, a, last);
		else if (++r)
			rb(a, last);
	}
	sort(b, a, i, last);
	while (r-- && count_stack(*a, *a) + i != size)
		rrb(a, last);
	rev_sort(a, b, size - i, last);
	while (i--)
		pb(b, a, last);
}
