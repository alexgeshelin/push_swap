/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohesheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 17:21:31 by ohesheli          #+#    #+#             */
/*   Updated: 2016/11/24 17:21:32 by ohesheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char const *str)
{
	int count;
	int sign;
	int res;

	sign = 1;
	count = 0;
	res = 0;
	while (str[count] == ' ' || str[count] == 10 || str[count] == 11
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
