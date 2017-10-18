/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohesheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 14:49:21 by ohesheli          #+#    #+#             */
/*   Updated: 2017/03/15 14:55:26 by ohesheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_atol(char const *str)
{
	int		count;
	long	sign;
	long	res;

	sign = 1;
	count = 0;
	res = 0;
	while (str[count] == ' ' || str[count] == 10 || str[count] == 11\
		|| str[count] == 12 || str[count] == 13 || str[count] == 9)
		count++;
	if (str[count] == '+' && str[count + 1] >= '0' && str[count + 1] <= '9')
		count++;
	else	if (str[count] == '-' && str[count + 1] >= '0' &&
				str[count + 1] <= '9')
	{
		sign = -1;
		count++;
	}
	while (str[count] >= '0' && str[count] <= '9')
	{
		res = res * 10 + str[count] - '0';
		count++;
	}
	return (sign * res);
}
