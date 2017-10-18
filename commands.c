/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohesheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 19:53:03 by ohesheli          #+#    #+#             */
/*   Updated: 2017/03/13 19:53:04 by ohesheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_command(t_command **last, t_command *node)
{
	(*last)->next = node;
	node->prev = *last;
	*last = node;
}

void		print_commands(t_command *node)
{
	if (!node)
		return ;
	while (node)
	{
		ft_putstr(node->str);
		ft_putchar('\n');
		node = node->next;
	}
}

void		optimize_commands(t_command **node)
{
	t_command *crawler;

	if (!(*node))
		return ;
	crawler = (*node)->next;
	while (crawler && crawler->next)
	{
		if (is_useless(crawler) && crawler != *node)
		{
			delete_command(crawler->next);
			crawler = crawler->prev;
			delete_command(crawler->next);
		}
		else
			crawler = crawler->next;
	}
}

void		delete_command(t_command *node)
{
	if (node->prev)
		node->prev->next = node->next;
	if (node->next)
		node->next->prev = node->prev;
	free(node->str);
	node->str = NULL;
	free(node);
}

t_command	*create_command(char *str)
{
	t_command *node;

	if (!(node = (t_command*)malloc(sizeof(t_command))))
		return (NULL);
	if (!(node->str = (char*)malloc(sizeof(char) * 4)))
		return (NULL);
	ft_strcpy(node->str, str);
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
