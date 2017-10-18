/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohesheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 14:43:41 by ohesheli          #+#    #+#             */
/*   Updated: 2017/03/15 14:43:44 by ohesheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	visualize(t_stack *a, t_stack *b)
{
	int z;
	int y;

	y = count_stack(a, a);
	z = count_stack(b, b);
	while (z || y)
	{
		if (y && y >= z)
		{
			ft_printf("%13d  ", a->n);
			y--;
			a = a->next;
		}
		else
			ft_printf("               ");
		if (z && z >= y + 1)
		{
			ft_printf("%13d  \n", b->n);
			z--;
			b = b->next;
		}
		else
			ft_printf("   \n");
	}
	ft_printf("\n");
}

void	operate_stacks(char *str, t_stack **a, t_stack **b, int v)
{
	if (ft_strequ(str, "sa"))
	{
		swap(a);
		if (v)
			visualize(*a, *b);
	}
	else	if (ft_strequ(str, "sb"))
	{
		swap(b);
		if (v)
			visualize(*a, *b);
	}
	else	if (ft_strequ(str, "ss"))
	{
		swap(a);
		swap(b);
		if (v)
			visualize(*a, *b);
	}
	else
		operate_stacks2(str, a, b, v);
}

void	operate_stacks2(char *str, t_stack **a, t_stack **b, int v)
{
	if (ft_strequ(str, "pa"))
	{
		op_push(a, b);
		if (v)
			visualize(*a, *b);
	}
	else	if (ft_strequ(str, "ra"))
	{
		rotate(a);
		if (v)
			visualize(*a, *b);
	}
	else	if (ft_strequ(str, "rb"))
	{
		rotate(b);
		if (v)
			visualize(*a, *b);
	}
	else
		operate_stacks3(str, a, b, v);
}

void	operate_stacks3(char *str, t_stack **a, t_stack **b, int v)
{
	if (ft_strequ(str, "rr"))
	{
		rotate(a);
		rotate(b);
		if (v)
			visualize(*a, *b);
	}
	else	if (ft_strequ(str, "rra"))
	{
		rrotate(a);
		if (v)
			visualize(*a, *b);
	}
	else	if (ft_strequ(str, "rrb"))
	{
		rrotate(b);
		if (v)
			visualize(*a, *b);
	}
	else
		operate_stacks4(str, a, b, v);
}

void	operate_stacks4(char *str, t_stack **a, t_stack **b, int v)
{
	if (ft_strequ(str, "rrr"))
	{
		rrotate(a);
		rrotate(b);
		if (v)
			visualize(*a, *b);
	}
	else	if (ft_strequ(str, "pb"))
	{
		op_push(b, a);
		if (v)
			visualize(*a, *b);
	}
	else
	{
		ft_putstr("Error\n");
		free_stacks(a, b);
		exit(0);
	}
}
