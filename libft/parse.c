/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohesheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 18:38:24 by ohesheli          #+#    #+#             */
/*   Updated: 2017/02/10 18:39:03 by ohesheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	read_specifiers(va_list ap, const char **str, int *n)
{
	t_conversion	*conv;

	conv = (t_conversion*)malloc(sizeof(t_conversion));
	conv->width = 0;
	conv->precision = -1;
	conv->flags = 0;
	while (**str)
	{
		if (ft_strchr("#0-+ hljz", **str))
			conv->flags = set_flag(str, conv->flags);
		else	if (ft_isdigit(**str))
			conv->width = set_width(str);
		else	if (**str == '.')
			conv->precision = set_precision(str);
		else	if (**str)
		{
			make_conv(conv, ap, str, n);
			free(conv);
			return ;
		}
	}
	free(conv);
}

int		set_flag(const char **str, int flag)
{
	if (**str == '#' && (*str)++)
		flag = flag | F_HASH;
	else	if (**str == '0' && (*str)++)
		flag = flag | F_ZERO;
	else	if (**str == '-' && (*str)++)
		flag = flag | F_MINUS;
	else	if (**str == '+' && (*str)++)
		flag = flag | F_PLUS;
	else	if (**str == ' ' && (*str)++)
		flag = flag | F_SPACE;
	else	if (**str == 'h' && (*str)[1] && (*str)[1] == 'h' &&\
			(*str = *str + 2))
		flag = flag | M_HH;
	else	if (**str == 'h' && (*str)++)
		flag = flag | M_H;
	else	if (**str == 'l' && (*str)[1] && (*str)[1] == 'l' &&\
			(*str = *str + 2))
		flag = flag | M_LL;
	else	if (**str == 'l' && (*str)++)
		flag = flag | M_L;
	else	if (**str == 'j' && (*str)++)
		flag = flag | M_J;
	else	if (**str == 'z' && (*str)++)
		flag = flag | M_Z;
	return (flag);
}

int		set_width(const char **str)
{
	const char *n;

	n = *str;
	while (**str >= '0' && **str <= '9')
	{
		(*str)++;
	}
	return (ft_atoi(n));
}

int		set_precision(const char **str)
{
	const char *n;

	(*str)++;
	n = *str;
	if (!(**str >= '0' && **str <= '9'))
		return (0);
	while (**str >= '0' && **str <= '9')
	{
		(*str)++;
	}
	return (ft_atoi(n));
}
