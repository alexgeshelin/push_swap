/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohesheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 18:44:44 by ohesheli          #+#    #+#             */
/*   Updated: 2017/02/10 18:45:06 by ohesheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	c_func(t_conversion *conv, va_list ap, int *n, char ch)
{
	int c;

	if (ch == 'C' || ch == 'c')
		c = va_arg(ap, int);
	else
		c = ch;
	if (conv->width > 1 && !(conv->flags & F_MINUS))
		make_padding(conv->width - 1, (conv->flags & F_ZERO));
	write(1, &c, 1);
	if (conv->width > 1 && (conv->flags & F_MINUS))
		make_padding(conv->width - 1, 0);
	if (conv->width >= 1)
		*n = *n + conv->width;
	else
		*n = *n + 1;
	c = ch;
}

void	make_padding(int n, int zero)
{
	char ch;

	ch = ' ';
	if (zero)
		ch = '0';
	while (n--)
		ft_putchar(ch);
}

void	s_func(t_conversion *conv, va_list ap, int *n, char ch)
{
	char*str;
	int len;

	str = va_arg(ap, char*);
	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	if (len > conv->precision && conv->precision > -1)
		len = conv->precision;
	if (conv->width > len && !(conv->flags & F_MINUS))
		make_padding(conv->width - len, (conv->flags & F_ZERO));
	write(1, str, len);
	if (conv->width > len && (conv->flags & F_MINUS))
		make_padding(conv->width - len, 0);
	if (conv->width > len)
		*n = *n + conv->width;
	else
		*n = *n + len;
	len = ch;
}

void	p_func(t_conversion *conv, va_list ap, int *n, char ch)
{
	unsigned long long p;

	if (ch == 'p')
	{
		p = va_arg(ap, unsigned long long);
		d_conv(conv, p, n, 'p');
	}
}

void	n_func(t_conversion *conv, va_list ap, int *n, char ch)
{
	int *p;

	if (conv && ch == 'n')
	{
		p = va_arg(ap, int*);
		*p = *n;
	}
}
