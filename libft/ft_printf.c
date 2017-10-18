/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohesheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 18:37:53 by ohesheli          #+#    #+#             */
/*   Updated: 2017/02/10 18:38:11 by ohesheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			n;
	const char	*str;

	va_start(ap, format);
	str = format;
	n = 0;
	while (*str)
	{
		if (*str == '%' && str++)
			read_specifiers(ap, &str, &n);
		else
		{
			write(1, str, 1);
			n++;
			str++;
		}
	}
	va_end(ap);
	return (n);
}
