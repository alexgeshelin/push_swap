/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohesheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 18:48:03 by ohesheli          #+#    #+#             */
/*   Updated: 2016/11/26 18:57:31 by ohesheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, void const *src, size_t len)
{
	size_t	i;

	if (dst > src)
	{
		i = len;
		while (i)
		{
			((unsigned char*)dst)[i - 1] = ((unsigned char*)src)[i - 1];
			i--;
		}
	}
	else	if (dst < src)
	{
		i = 0;
		while (i < len)
		{
			((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
			i++;
		}
	}
	return (dst);
}
