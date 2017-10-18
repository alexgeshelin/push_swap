/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohesheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 18:40:20 by ohesheli          #+#    #+#             */
/*   Updated: 2017/02/10 18:43:53 by ohesheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	make_conv(t_conversion *conv, va_list ap, const char **str, int *n)
{
	int		i;
	char	ch[2];

	i = 0;
	ch[0] = **str;
	ch[1] = '\0';
	(*str)++;
	while (g_func[i].str)
	{
		if (ft_strstr(g_func[i].str, ch))
		{
			g_func[i].f(conv, ap, n, ch[0]);
			return ;
		}
		i++;
	}
	if (ch[0] && !(g_func[i].str))
		c_func(conv, ap, n, ch[0]);
}

void	d_func(t_conversion *conv, va_list ap, int *n, char ch)
{
	t_d	d;

	if (conv->flags & M_J)
		d_conv(conv, (d.j = va_arg(ap, intmax_t)), n, ch);
	else	if (conv->flags & M_Z)
		d_conv(conv, (d.z = va_arg(ap, ssize_t)), n, ch);
	else	if (conv->flags & M_LL)
		d_conv(conv, (d.ll = va_arg(ap, long long)), n, ch);
	else	if (conv->flags & M_L || ch == 'D')
		d_conv(conv, (d.l = va_arg(ap, long)), n, ch);
	else	if (conv->flags & M_HH)
		d_conv(conv, (d.hh = va_arg(ap, int)), n, ch);
	else	if (conv->flags & M_H)
		d_conv(conv, (d.h = va_arg(ap, int)), n, ch);
	else
		d_conv(conv, (d.i = va_arg(ap, int)), n, ch);
}

void	ud_func(t_conversion *conv, va_list ap, int *n, char ch)
{
	t_ud ud;

	if (ch == 'O')
		d_conv(conv, (ud.l = va_arg(ap, unsigned long)), n, 'o');
	else	if (ch == 'U')
		d_conv(conv, (ud.l = va_arg(ap, unsigned long)), n, 'u');
	else	if (conv->flags & M_J)
		d_conv(conv, (ud.j = va_arg(ap, uintmax_t)), n, ch);
	else	if (conv->flags & M_Z)
		d_conv(conv, (ud.z = va_arg(ap, ssize_t)), n, ch);
	else	if (conv->flags & M_LL)
		d_conv(conv, (ud.ll = va_arg(ap, unsigned long long)), n, ch);
	else	if (conv->flags & M_L || ch == 'D')
		d_conv(conv, (ud.l = va_arg(ap, unsigned long)), n, ch);
	else	if (conv->flags & M_HH)
		d_conv(conv, (ud.hh = va_arg(ap, unsigned int)), n, ch);
	else	if (conv->flags & M_H)
		d_conv(conv, (ud.h = va_arg(ap, unsigned int)), n, ch);
	else
		d_conv(conv, (ud.i = va_arg(ap, unsigned int)), n, ch);
}

void	d_conv(t_conversion *conv, long long var, int *n, char ch)
{
	char	*str;
	char	*prefix;

	conv->neg = 0;
	prefix = make_prefix(conv, var, ch);
	if (ch == 'u' || ch == 'U')
		str = lltoa(var, 10, 0);
	if (ch == 'd' || ch == 'i' || ch == 'D')
		str = lltoa(ABS(var), 10, 0);
	if (ch == 'o')
		str = lltoa(var, 8, 0);
	if (ch == 'x' || ch == 'p')
		str = lltoa(var, 16, 0);
	if (ch == 'X')
		str = lltoa(var, 16, 32);
	str = ft_freejoin(prefix, make_precision(conv, str, ch));
	if (ch == 'o' && var == 0 && conv->precision == 0 && conv->flags & F_HASH)
		ft_strcpy(str, "0");
	else	if (var == 0 && conv->precision == 0 && ch != 'p')
		ft_strcpy(str, "");
	str = make_d_padding(conv, str);
	*n = *n + ft_strlen(str);
	ft_putstr(str);
	free(str);
}

char	*ft_freejoin(char *s1, char *s2)
{
	char	*str;

	str = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (str);
}
