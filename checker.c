/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohesheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 17:22:26 by ohesheli          #+#    #+#             */
/*   Updated: 2017/03/15 19:52:59 by ohesheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	char		*str;
	int			v;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	if (!(handle_args(argc, argv, &a, &v)))
	{
		ft_putstr("Error\n");
		return (0);
	}
	while (get_next_line(0, &str))
	{
		operate_stacks(str, &a, &b, v);
		free(str);
	}
	if (check_sort(a))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	free_stacks(&a, &b);
	return (0);
}
