/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohesheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 13:44:29 by ohesheli          #+#    #+#             */
/*   Updated: 2017/03/16 13:44:32 by ohesheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a, t_command **command)
{
	swap(a);
	push_command(command, create_command("sa"));
}

void	sb(t_stack **a, t_command **command)
{
	swap(a);
	push_command(command, create_command("sb"));
}
