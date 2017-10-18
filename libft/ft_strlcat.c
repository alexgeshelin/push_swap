/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohesheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 14:17:01 by ohesheli          #+#    #+#             */
/*   Updated: 2016/11/24 14:17:03 by ohesheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char const *src, size_t size)
{
	char		*s1;
	const char	*s2;
	size_t		n;
	size_t		len;

	s1 = dst;
	s2 = src;
	n = size;
	while (*s1 != '\0' && n-- != 0)
		s1++;
	len = s1 - dst;
	n = size - len;
	if (n == 0)
		return (len + ft_strlen(src));
	while (*s2)
	{
		if (n > 1)
		{
			*s1++ = *s2;
			n--;
		}
		s2++;
	}
	*s1 = '\0';
	return (len + (s2 - src));
}
