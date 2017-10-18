/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohesheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 19:50:43 by ohesheli          #+#    #+#             */
/*   Updated: 2016/11/29 17:27:48 by ohesheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(char const *s1, char const *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (!n)
		return (0);
	while (*s1 && *s2 && i < n - 1)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
		i++;
	}
	if (*s1 != *s2 && n != 0)
		return ((unsigned char)*s1 - (unsigned char)*s2);
	return (0);
}
