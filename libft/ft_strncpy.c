/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohesheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 20:01:02 by ohesheli          #+#    #+#             */
/*   Updated: 2016/11/23 20:01:09 by ohesheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, char const *src, size_t len)
{
	unsigned int counter;

	counter = 0;
	while (counter < len)
	{
		if (src[counter] == '\0')
		{
			while (counter < len)
			{
				dst[counter] = '\0';
				counter++;
			}
		}
		else
		{
			dst[counter] = src[counter];
			counter++;
		}
	}
	return (dst);
}
