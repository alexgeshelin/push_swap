/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohesheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 13:01:37 by ohesheli          #+#    #+#             */
/*   Updated: 2016/11/23 13:17:33 by ohesheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(int n)
{
	int res;

	res = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		res = res + 2;
		n = n / 10;
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		res++;
	}
	return (res);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = num_len(n);
	if ((str = ft_strnew(len)) == 0)
		return (NULL);
	len--;
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (n < 0)
	{
		str[0] = '-';
		str[len--] = '0' - (n % 10);
		n = n / 10 * -1;
	}
	while (n > 0)
	{
		str[len--] = '0' + n % 10;
		n = n / 10;
	}
	return (str);
}
