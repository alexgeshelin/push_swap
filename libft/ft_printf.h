/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohesheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 13:37:05 by ohesheli          #+#    #+#             */
/*   Updated: 2017/03/15 18:45:39 by ohesheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# define F_HASH 1
# define F_ZERO 2
# define F_MINUS 4
# define F_PLUS 8
# define F_SPACE 16
# define M_H 32
# define M_HH 64
# define M_L 128
# define M_LL 256
# define M_J 512
# define M_Z 1024
# define ABS(x) ((x) < 0 ? -(x) : (x))

typedef struct	s_conversion
{
	int		flags;
	int		width;
	int		precision;
	int		neg;
}				t_conversion;

typedef struct	s_d
{
	short			h;
	signed char		hh;
	int				i;
	long			l;
	long long		ll;
	intmax_t		j;
	ssize_t			z;
}				t_d;

typedef struct	s_ud
{
	unsigned short		h;
	unsigned char		hh;
	unsigned int		i;
	unsigned long		l;
	unsigned long long	ll;
	uintmax_t			j;
	size_t				z;
}				t_ud;

int				ft_printf(const char *format, ...);
void			read_specifiers(va_list ap, const char **fmt, int *n);
int				set_flag(const char **str, int flag);
int				set_width(const char **str);
int				set_precision(const char **str);
void			d_conv(t_conversion *conv, long long var, int *n, char ch);
void			d_func(t_conversion *conv, va_list ap, int *n, char ch);
char			*lltoa(unsigned long long nbr, int base, int alt);
void			make_conv(t_conversion *conv, va_list ap,\
				const char **str, int *n);
int				get_nbr_size(unsigned long long nbr, int base);
char			*make_precision(t_conversion *conv, char *str, char ch);
char			*make_d_padding(t_conversion *conv, char *str);
void			make_padding(int n, int zero);
char			*make_prefix(t_conversion *conv, long long var, char ch);
void			c_func(t_conversion *conv, va_list ap, int *n, char ch);
void			s_func(t_conversion *conv, va_list ap, int *n, char ch);
void			p_func(t_conversion *conv, va_list ap, int *n, char ch);
void			n_func(t_conversion *conv, va_list ap, int *n, char ch);
void			ud_func(t_conversion *conv, va_list ap, int *n, char ch);
char			*ft_freejoin(char *s1, char *s2);

typedef struct	s_func
{
	char	*str;
	void	(*f)(t_conversion*, va_list, int*, char);
}				t_func;

static const	t_func	g_func[] = {
	{"idD", d_func},
	{"cC", c_func},
	{"sS", s_func},
	{"p", p_func},
	{"n", n_func},
	{"OUouxX", ud_func},
	{NULL, NULL}
};

#endif
