/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohesheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:16:31 by ohesheli          #+#    #+#             */
/*   Updated: 2016/11/26 20:51:14 by ohesheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*cat;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if ((cat = ft_strnew(ft_strlen(s1) + ft_strlen(s2))) == 0)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		cat[i++] = s1[j++];
	j = 0;
	while (s2[j])
		cat[i++] = s2[j++];
	return (cat);
}
