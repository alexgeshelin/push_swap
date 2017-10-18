/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohesheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 15:16:11 by ohesheli          #+#    #+#             */
/*   Updated: 2017/03/15 19:46:07 by ohesheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		need_for_push(t_stack **a, int size, int pivot)
{
	t_stack *crawler;

	if (!(*a))
		return (0);
	crawler = *a;
	while (size--)
	{
		if (crawler->n <= pivot)
			return (1);
		crawler = crawler->next;
	}
	return (0);
}

int		need_for_rev_push(t_stack **a, int size, int pivot)
{
	t_stack *crawler;

	crawler = *a;
	if (!(*a))
		return (0);
	while (size--)
	{
		if (crawler->n > pivot)
			return (1);
		crawler = crawler->next;
	}
	return (0);
}

int		count_stack(t_stack *stack, t_stack *end)
{
	t_stack *crawler;
	int		res;

	if (!stack)
		return (0);
	crawler = stack;
	res = 1;
	while (crawler->next != end)
	{
		res++;
		crawler = crawler->next;
	}
	return (res);
}

void	sort_little_all(t_stack **a, t_command **last)
{
	t_stack *b;

	b = *a;
	if (b->next->next->n < b->next->n && b->next->next->n > b->n)
	{
		sa(a, last);
		ra(a, last);
	}
	if (b->n < b->next->n && b->n > b->next->next->n)
		rra(a, last);
	if (b->n > b->next->n && b->n < b->next->next->n)
		sa(a, last);
	if (b->next->n < b->n && b->next->n > b->next->next->n)
	{
		rra(a, last);
		sa(a, last);
	}
	if (b->next->next->n > b->next->n && b->next->next->n < b->n)
		ra(a, last);
}

void	rev_sort_little_all(t_stack **a, t_command **last)
{
	t_stack *b;

	b = *a;
	if (b->n < b->next->n && b->next->n > b->next->next->n\
	&& b->n < b->next->next->n)
		rb(a, last);
	else	if (b->n < b->next->n && b->next->n > b->next->next->n\
	&& b->n > b->next->next->n)
		sb(a, last);
	else	if (b->n > b->next->n && b->next->n < b->next->next->n\
	&& b->n < b->next->next->n)
		rrb(a, last);
	else	if (b->n < b->next->n && b->next->n < b->next->next->n\
	&& b->n < b->next->next->n)
	{
		sb(a, last);
		rrb(a, last);
	}
	else	if (b->n > b->next->n && b->next->n < b->next->next->n\
	&& b->n > b->next->next->n)
	{
		rrb(a, last);
		sb(a, last);
	}
}
