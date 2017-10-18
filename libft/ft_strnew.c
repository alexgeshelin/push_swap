/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohesheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 15:45:53 by ohesheli          #+#    #+#             */
/*   Updated: 2016/11/21 16:35:31 by ohesheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char			*str;
	unsigned int	i;

	if ((str = (char*)malloc(sizeof(char) * (size + 1))) == 0)
		return (NULL);
	i = 0;
	while (i <= size)
		str[i++] = 0;
	return (str);
}
