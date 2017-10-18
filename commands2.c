/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohesheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 15:05:24 by ohesheli          #+#    #+#             */
/*   Updated: 2017/03/14 15:05:25 by ohesheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_useless(t_command *node)
{
	char *s1;
	char *s2;

	s1 = node->str;
	s2 = node->next->str;
	if (ft_strequ(s1, "ra") && ft_strequ(s2, "rra"))
		return (1);
	if (ft_strequ(s1, "rb") && ft_strequ(s2, "rrb"))
		return (1);
	if (ft_strequ(s1, "rra") && ft_strequ(s2, "ra"))
		return (1);
	if (ft_strequ(s1, "rrb") && ft_strequ(s2, "rb"))
		return (1);
	if (ft_strequ(s1, "pa") && ft_strequ(s2, "pb"))
		return (1);
	if (ft_strequ(s1, "pb") && ft_strequ(s2, "pa"))
		return (1);
	return (0);
}

void	rra(t_stack **a, t_command **command)
{
	rrotate(a);
	push_command(command, create_command("rra"));
}

void	pa(t_stack **a, t_stack **b, t_command **command)
{
	op_push(a, b);
	push_command(command, create_command("pa"));
}

void	ra(t_stack **a, t_command **command)
{
	rotate(a);
	push_command(command, create_command("ra"));
}

void	pb(t_stack **a, t_stack **b, t_command **command)
{
	op_push(b, a);
	push_command(command, create_command("pb"));
}
