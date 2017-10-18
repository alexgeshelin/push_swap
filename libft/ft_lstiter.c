/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohesheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 20:05:52 by ohesheli          #+#    #+#             */
/*   Updated: 2016/11/26 20:59:55 by ohesheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*next;

	if (lst == NULL)
		return ;
	while (lst->next)
	{
		next = lst->next;
		f(lst);
		lst = next;
	}
	f(lst);
}
