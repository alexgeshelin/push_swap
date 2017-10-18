/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohesheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 16:17:30 by ohesheli          #+#    #+#             */
/*   Updated: 2016/11/24 16:17:32 by ohesheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char const *big, char const *little)
{
	size_t	len;

	if ((len = ft_strlen(little)) == 0)
		return ((char*)big);
	while (*big)
	{
		if (*big == *little)
		{
			if ((ft_strncmp(big, little, len)) == 0)
				return ((void*)big);
		}
		big++;
	}
	return (NULL);
}
