/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohesheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 13:56:09 by ohesheli          #+#    #+#             */
/*   Updated: 2016/11/21 15:59:41 by ohesheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*mem;
	unsigned int	i;

	if ((mem = (unsigned char*)malloc(sizeof(unsigned char) * size)) == NULL)
		return (NULL);
	i = 0;
	while (i < size)
		mem[i++] = 0;
	return ((void*)mem);
}
