/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohesheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 20:02:37 by ohesheli          #+#    #+#             */
/*   Updated: 2017/02/12 20:02:42 by ohesheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **a)
{
	t_stack	*crawler;

	if (!(*a))
		return ;
	if ((*a)->next == *a)
		return ;
	crawler = (*a)->next;
	while (crawler->next != *a)
		crawler = crawler->next;
	crawler->next = (*a)->next;
	(*a)->next = (*a)->next->next;
	crawler->next->next = *a;
	*a = crawler->next;
}

void	op_push(t_stack **a, t_stack **b)
{
	t_stack *buff;

	if (!(*b))
		return ;
	buff = pop(b);
	push(a, buff);
}

void	rotate(t_stack **a)
{
	if (*a)
		*a = (*a)->next;
}

void	rrotate(t_stack **a)
{
	t_stack *crawler;

	if (*a)
	{
		crawler = *a;
		while (crawler->next != *a)
			crawler = crawler->next;
		*a = crawler;
	}
}
