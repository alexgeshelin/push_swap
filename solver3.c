/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohesheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 15:44:32 by ohesheli          #+#    #+#             */
/*   Updated: 2017/03/17 15:44:36 by ohesheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_sort(t_stack **a, t_stack **b, t_command **crawler,\
		t_command *begin)
{
	if (count_stack(*a, *a) <= 7)
		alt_sort(a, b, count_stack(*a, *a), crawler);
	else
		sort(a, b, count_stack(*a, *a), crawler);
	check_first(a, crawler);
	check_last(a, crawler);
	optimize_commands(&(begin->next));
}
