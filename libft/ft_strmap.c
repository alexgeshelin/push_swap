/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohesheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 18:25:40 by ohesheli          #+#    #+#             */
/*   Updated: 2016/11/26 21:03:15 by ohesheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*str;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	if ((str = ft_strnew(ft_strlen(s))) == 0)
		return (NULL);
	while (s[i])
	{
		str[i] = f(s[i]);
		i++;
	}
	return (str);
}
