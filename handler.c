/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohesheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 16:32:18 by ohesheli          #+#    #+#             */
/*   Updated: 2017/03/15 19:56:07 by ohesheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		handle_args(int argc, char **argv, t_stack **stack, int *v)
{
	long	len;

	*v = 0;
	while (argc-- != 1)
	{
		if (ft_strequ(argv[argc], "-v"))
		{
			*v = 1;
			return (1);
		}
		if (!(check_symbols(argv[argc])))
			return (0);
		len = ft_strlen(argv[argc]);
		if (len > 11)
			return (0);
		len = ft_atol(argv[argc]);
		if (len > 2147483647 || len < -2147483648)
			return (0);
		if (!(check_equal(*stack, len))\
			|| !(*stack = push(stack, create_elem(len))))
			return (0);
	}
	return (1);
}

int		check_symbols(char *str)
{
	if (*str == '-' && str[1] && ft_isdigit(str[1]))
		str++;
	while (*str)
	{
		if (!(ft_isdigit(*str)))
			return (0);
		str++;
	}
	return (1);
}

int		check_equal(t_stack *stack, int len)
{
	t_stack *crawl;

	if (!stack)
		return (1);
	crawl = stack->next;
	if (len == stack->n)
		return (0);
	while (crawl != stack)
	{
		if (crawl->n == len)
			return (0);
		crawl = crawl->next;
	}
	return (1);
}

int		check_sort(t_stack *a)
{
	t_stack *crawler;

	if (a->next == a)
		return (1);
	crawler = a;
	while (crawler->next != a)
	{
		if (crawler->n > crawler->next->n)
			return (0);
		crawler = crawler->next;
	}
	return (1);
}

void	free_stacks(t_stack **a, t_stack **b)
{
	t_stack *buffer;

	while (*a)
	{
		buffer = pop(a);
		free(buffer);
	}
	while (*b)
	{
		buffer = pop(b);
		free(buffer);
	}
}
