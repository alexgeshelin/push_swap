/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohesheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 18:52:32 by ohesheli          #+#    #+#             */
/*   Updated: 2016/11/26 21:02:26 by ohesheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list			*node;
	unsigned char	*cont_copy;

	if ((node = ft_memalloc(sizeof(t_list))) == 0)
		return (NULL);
	if (content == NULL)
	{
		node->content = NULL;
		node->content_size = 0;
		node->next = NULL;
		return (node);
	}
	if ((cont_copy = ft_memalloc(content_size)) == 0)
		return (NULL);
	cont_copy = ft_memcpy(cont_copy, content, content_size);
	node->content = cont_copy;
	node->content_size = content_size;
	node->next = NULL;
	return (node);
}
