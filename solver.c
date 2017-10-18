/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohesheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 16:35:47 by ohesheli          #+#    #+#             */
/*   Updated: 2017/03/15 19:46:53 by ohesheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack **a, t_stack **b, int size, t_command **last)
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
		if ((*a)->n <= pivot && ++i)
			pb(a, b, last);
		else if (++r)
			ra(a, last);
	}
	while (r-- && count_stack(*a, *a) + i != size)
		rra(a, last);
	sort(a, b, size - i, last);
	rev_sort(b, a, i, last);
	while (i--)
		pa(a, b, last);
}

void	rev_sort(t_stack **a, t_stack **b, int size, t_command **last)
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
		if ((*a)->n > pivot && ++i)
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

void	sort_little(t_stack **a, t_stack **b, int size, t_command **last)
{
	if (count_stack(*a, *a) == 3)
	{
		sort_little_all(a, last);
		return ;
	}
	if ((*a)->n > (*a)->next->n && (*b)->n < (*b)->next->n)
	{
		swap(a);
		swap(b);
		push_command(last, create_command("ss"));
	}
	else	if ((*a)->n > (*a)->next->n)
		sa(a, last);
	if (size == 3)
	{
		ra(a, last);
		if ((*a)->n > (*a)->next->n)
			sa(a, last);
		rra(a, last);
		if ((*a)->n > (*a)->next->n)
			sa(a, last);
	}
}

void	rev_sort_little(t_stack **a, t_stack **b, int size, t_command **last)
{
	if (count_stack(*a, *a) == 3)
	{
		rev_sort_little_all(a, last);
		return ;
	}
	if ((*a)->n < (*a)->next->n && (*b)->n > (*b)->next->n)
	{
		swap(a);
		swap(b);
		push_command(last, create_command("ss"));
	}
	else	if ((*a)->n < (*a)->next->n)
		sb(a, last);
	if (size == 3)
	{
		rb(a, last);
		if ((*a)->n < (*a)->next->n)
			sb(a, last);
		rrb(a, last);
		if ((*a)->n < (*a)->next->n)
			sb(a, last);
	}
}
