/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohesheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 19:49:01 by ohesheli          #+#    #+#             */
/*   Updated: 2016/11/26 20:59:43 by ohesheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*crawler;
	t_list	*next;

	crawler = *alst;
	while (crawler->next)
	{
		next = crawler->next;
		ft_lstdelone(&crawler, del);
		crawler = next;
	}
	ft_lstdelone(&crawler, del);
	*alst = NULL;
}
