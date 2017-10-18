/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohesheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:04:14 by ohesheli          #+#    #+#             */
/*   Updated: 2016/11/26 20:51:02 by ohesheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		b;
	int		e;
	int		i;
	char	*trim;

	if (s == NULL)
		return (NULL);
	b = 0;
	e = 0;
	i = 0;
	while (s[b] == ' ' || s[b] == '\n' || s[b] == '\t')
		b++;
	if (s[b] == 0)
		return (trim = ft_strnew(0));
	while (s[e + 1])
		e++;
	while (s[e] == ' ' || s[e] == '\n' || s[e] == '\t')
		e--;
	if ((trim = ft_strnew(e - b + 1)) == 0)
		return (NULL);
	while (b <= e)
		trim[i++] = s[b++];
	return (trim);
}
