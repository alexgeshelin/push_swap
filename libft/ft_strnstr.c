/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohesheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 16:55:07 by ohesheli          #+#    #+#             */
/*   Updated: 2016/11/24 16:55:09 by ohesheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *big, char const *little, size_t len)
{
	size_t	nlen;
	size_t	i;

	i = 0;
	if (big == NULL)
		i = big[0];
	if ((nlen = ft_strlen(little)) == 0)
		return ((char*)big);
	if (nlen > len)
		return (NULL);
	len = len - nlen + 1;
	while (i < len && *big != 0)
	{
		if ((ft_strncmp(big, little, nlen)) == 0)
			return ((void*)big);
		i++;
		big++;
	}
	return (NULL);
}
