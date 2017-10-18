/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohesheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 15:49:01 by ohesheli          #+#    #+#             */
/*   Updated: 2016/11/24 15:49:03 by ohesheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char const *s, int c)
{
	char	ch;
	char	*chr;
	int		i;

	i = 0;
	chr = NULL;
	ch = c;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == ch)
		{
			chr = (char *)&(s[i]);
			break ;
		}
		i--;
	}
	return (chr);
}
