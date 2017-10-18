/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohesheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 20:13:58 by ohesheli          #+#    #+#             */
/*   Updated: 2016/11/26 21:02:06 by ohesheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_list;
	t_list	*crawler;

	if (lst == NULL)
		return (NULL);
	new_list = f(lst);
	crawler = new_list;
	while (lst->next)
	{
		lst = lst->next;
		crawler->next = f(lst);
		crawler = crawler->next;
	}
	return (new_list);
}
