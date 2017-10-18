/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohesheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 17:22:12 by ohesheli          #+#    #+#             */
/*   Updated: 2017/02/13 17:22:17 by ohesheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		*create_elem(int n)
{
	t_stack *elem;

	if (!(elem = (t_stack*)malloc(sizeof(t_stack))))
		return (NULL);
	elem->n = n;
	elem->next = NULL;
	return (elem);
}

t_stack		*push(t_stack **head, t_stack *elem)
{
	t_stack *crawler;

	if (!elem)
		return (NULL);
	if (!(*head))
	{
		*head = elem;
		elem->next = elem;
	}
	else
	{
		crawler = *head;
		while (crawler->next != *head)
			crawler = crawler->next;
		crawler->next = elem;
		elem->next = *head;
		*head = elem;
	}
	return (elem);
}

t_stack		*pop(t_stack **head)
{
	t_stack *crawler;

	if (!(*head))
		return (NULL);
	if ((*head)->next == *head)
	{
		crawler = *head;
		*head = NULL;
		return (crawler);
	}
	crawler = *head;
	while (crawler->next != *head)
		crawler = crawler->next;
	crawler->next = (*head)->next;
	crawler = *head;
	*head = (*head)->next;
	return (crawler);
}
