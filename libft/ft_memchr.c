/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohesheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:48:53 by ohesheli          #+#    #+#             */
/*   Updated: 2016/11/23 17:48:54 by ohesheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void const *s, int c, size_t n)
{
	unsigned char	ch;
	unsigned int	i;

	ch = c;
	i = 0;
	while (i < n)
	{
		if (((unsigned char*)s)[i] == ch)
			return ((void*)&(s[i]));
		i++;
	}
	return (NULL);
}
