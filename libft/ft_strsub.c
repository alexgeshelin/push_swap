/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohesheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 13:50:57 by ohesheli          #+#    #+#             */
/*   Updated: 2016/11/26 20:51:21 by ohesheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	if ((sub = ft_strnew(len)) == 0)
		return (NULL);
	while (i < len)
		sub[i++] = s[start++];
	return (sub);
}
