/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohesheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:59:52 by ohesheli          #+#    #+#             */
/*   Updated: 2016/11/26 20:55:07 by ohesheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *str, char c)
{
	int		res;

	res = 0;
	if (*str && *str != c)
		res++;
	while (str[1])
	{
		if (*str == c && str[1] != c)
			res++;
		str++;
	}
	return (res);
}

static char	*add_word(char const *str, char c)
{
	int		i;
	char	*word;

	i = 0;
	while (str[i] != c && str[i] != 0)
		i++;
	word = ft_strnew(i);
	i = 0;
	while (str[i] != c && str[i] != 0)
	{
		word[i] = str[i];
		i++;
	}
	return (word);
}

char		**ft_strsplit(char const *s, char c)
{
	int		words;
	char	**table;
	int		i;

	if (s == NULL)
		return (NULL);
	words = count_words(s, c);
	if ((table = (char**)malloc(sizeof(char*) * (words + 1))) == 0)
		return (0);
	i = 0;
	if (*s && *s != c)
		table[i++] = add_word(s, c);
	while (s[1])
	{
		if (*s == c && s[1] != c)
			table[i++] = add_word(&(s[1]), c);
		s++;
	}
	table[i] = NULL;
	return (table);
}
