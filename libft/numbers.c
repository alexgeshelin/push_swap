/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohesheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 18:41:57 by ohesheli          #+#    #+#             */
/*   Updated: 2017/02/10 19:03:40 by ohesheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*make_prefix(t_conversion *conv, long long var, char ch)
{
	char *str;

	if (!(str = ft_strnew(2)))
		return (NULL);
	if (ch == 'd' || ch == 'i' || ch == 'D')
	{
		if (var < 0 && (conv->neg = 1))
			str[0] = '-';
		else	if (conv->flags & F_PLUS && (conv->neg = 1))
			str[0] = '+';
		else	if (conv->flags & F_SPACE && (conv->neg = 1))
			str[0] = ' ';
	}
	if (ch == 'o' && (conv->flags & F_HASH) && var != 0)
	{
		if (conv->precision < get_nbr_size(var, 8) + 1)
			conv->precision = get_nbr_size(var, 8) + 1;
	}
	if ((ch == 'x' && (conv->flags & F_HASH) && var != 0 && (conv->neg = 2))\
		|| (ch == 'p' && (conv->neg = 2)))
		ft_strcpy(str, "0x");
	if (ch == 'X' && (conv->flags & F_HASH) && var != 0 && (conv->neg = 2))
		ft_strcpy(str, "0X");
	return (str);
}

char	*make_precision(t_conversion *conv, char *str, char ch)
{
	char*precision;
	int len;

	len = ft_strlen(str);
	if ((conv->flags & F_ZERO) && !(conv->flags & F_MINUS)\
		&& conv->precision == -1)
		conv->precision = conv->width - conv->neg;
	if (!(ft_strcmp(str, "0")) && ch == 'p' && conv->precision == 0)
		str[0] = '\0';
	if (conv->precision < len)
		return (str);
	precision = ft_strnew(conv->precision);
	ft_memset(&(precision[0]), '0', conv->precision - len);
	ft_strcpy(&(precision[conv->precision - len]), &(str[0]));
	free(str);
	return (precision);
}

char	*make_d_padding(t_conversion *conv, char *str)
{
	char	*padding;
	int		pad_len;
	char	*res;

	pad_len = conv->width - ft_strlen(str);
	if (pad_len <= 0)
		return (str);
	padding = ft_strnew(pad_len);
	ft_memset(padding, ' ', pad_len);
	if (conv->flags & F_MINUS)
		res = ft_strjoin(str, padding);
	else
		res = ft_strjoin(padding, str);
	free(str);
	free(padding);
	return (res);
}

char	*lltoa(unsigned long long nbr, int base, int alt)
{
	char	*str;
	int		size;

	size = get_nbr_size(nbr, base);
	if (!(str = ft_strnew(size)))
		return (NULL);
	while (1)
	{
		str[size - 1] = '0' + nbr % base;
		if (str[size - 1] > '9')
			str[size - 1] = str[size - 1] - ':' + 'a' - alt;
		nbr = nbr / base;
		size--;
		if (!nbr)
			break ;
	}
	return (str);
}

int		get_nbr_size(unsigned long long nbr, int base)
{
	int res;

	res = 0;
	while (1)
	{
		res++;
		nbr = nbr / base;
		if (!nbr)
			break ;
	}
	return (res);
}
