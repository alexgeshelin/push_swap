/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohesheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 19:21:55 by ohesheli          #+#    #+#             */
/*   Updated: 2016/11/26 21:03:03 by ohesheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *s1)
{
	char	*dup;

	if ((dup = ft_strnew(ft_strlen(s1))) == 0)
		return (NULL);
	ft_strcpy(dup, s1);
	return (dup);
}
