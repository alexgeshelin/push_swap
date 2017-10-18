/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohesheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:57:43 by ohesheli          #+#    #+#             */
/*   Updated: 2016/11/29 17:54:00 by ohesheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, void const *src, int c, size_t n)
{
	size_t			i;
	unsigned char	ch;

	i = 0;
	ch = c;
	while (i < n)
	{
		((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
		if (((unsigned char*)src)[i] == ch)
		{
			return (&(dst[i + 1]));
		}
		i++;
	}
	return (NULL);
}
