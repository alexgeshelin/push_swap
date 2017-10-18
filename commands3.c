/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohesheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 15:11:42 by ohesheli          #+#    #+#             */
/*   Updated: 2017/03/14 15:11:43 by ohesheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_stack **a, t_command **command)
{
	rotate(a);
	push_command(command, create_command("rb"));
}

void	rrb(t_stack **a, t_command **command)
{
	rrotate(a);
	push_command(command, create_command("rrb"));
}

void	check_last(t_stack **a, t_command **last)
{
	t_stack *crawler;
	t_stack *alast;

	crawler = *a;
	while (crawler->next != *a)
		crawler = crawler->next;
	alast = crawler;
	crawler = *a;
	while (crawler->next != alast)
		crawler = crawler->next;
	if (crawler->n > alast->n)
	{
		rrotate(a);
		push_command(last, create_command("rra"));
		rrotate(a);
		push_command(last, create_command("rra"));
		swap(a);
		push_command(last, create_command("sa"));
		rotate(a);
		push_command(last, create_command("ra"));
		rotate(a);
		push_command(last, create_command("ra"));
	}
}

void	check_first(t_stack **a, t_command **commands)
{
	t_stack	*crawler;

	crawler = *a;
	if (crawler->next->n < crawler->n)
	{
		swap(a);
		push_command(commands, create_command("sa"));
	}
}

void	free_commands(t_command *begin)
{
	t_command	*crawler;

	crawler = begin;
	while (begin->next)
	{
		begin = begin->next;
		delete_command(crawler);
		crawler = begin;
	}
	delete_command(crawler);
}
