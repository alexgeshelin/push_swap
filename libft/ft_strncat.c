/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohesheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 13:36:29 by ohesheli          #+#    #+#             */
/*   Updated: 2016/11/24 13:37:08 by ohesheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, char const *s2, size_t n)
{
	unsigned int i1;
	unsigned int i2;

	i1 = 0;
	i2 = 0;
	while (s1[i1])
		i1++;
	while (s2[i2] && i2 < n)
	{
		s1[i1] = s2[i2];
		i1++;
		i2++;
	}
	s1[i1] = '\0';
	return (s1);
}
