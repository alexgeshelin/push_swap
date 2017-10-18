/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohesheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 19:30:15 by ohesheli          #+#    #+#             */
/*   Updated: 2016/11/23 19:30:36 by ohesheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dst, char *src)
{
	int counter;

	counter = 0;
	while (src[counter])
	{
		dst[counter] = src[counter];
		counter++;
	}
	dst[counter] = src[counter];
	return (dst);
}
