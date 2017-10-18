/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohesheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 19:08:53 by ohesheli          #+#    #+#             */
/*   Updated: 2017/01/23 19:10:56 by ohesheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int const fd, char **line)
{
	char			buffer[BUFF_SIZE + 1];
	char			*str;
	static t_elem	*rem = NULL;
	int				n;

	ft_bzero(buffer, BUFF_SIZE + 1);
	if (!(rem = get_fd(rem, fd)))
		return (-1);
	while (!(ft_strchr(rem->str, '\n')))
	{
		ft_bzero(buffer, BUFF_SIZE + 1);
		if ((n = read(fd, buffer, BUFF_SIZE)) < 0)
			return (n);
		ft_bzero(&(buffer[n]), BUFF_SIZE - n);
		str = rem->str;
		rem->str = ft_strjoin(rem->str, buffer);
		ft_strdel(&str);
		if (n == 0)
			break ;
	}
	if (!(n = get_line(&(rem->str), line)))
		rem = del_fd(rem);
	return (n);
}

int		get_line(char **rem, char **line)
{
	char *str;

	if (**rem == '\0')
	{
		ft_strdel(rem);
		return (0);
	}
	else	if (ft_strchr(*rem, '\n'))
	{
		*line = ft_strsub(*rem, 0, SIZE_LINE);
		str = *rem;
		*rem = ft_strsub(ft_strchr(*rem, '\n') + 1, 0, SIZE_REST);
		ft_strdel(&str);
		return (1);
	}
	else	if (*rem)
	{
		*line = ft_strsub(*rem, 0, SIZE_LAST);
		*rem = ft_strsub(*rem, 0, 0);
		return (1);
	}
	return (0);
}

t_elem	*get_fd(t_elem *cur, int fd)
{
	t_elem	*res;

	if (!cur)
		return (res = create_fd(fd));
	if (cur->fd == fd)
		return (cur);
	res = cur->next;
	while (res != cur)
	{
		if (res->fd == fd)
			break ;
		res = res->next;
	}
	if (res->fd != fd)
	{
		if (!(res = create_fd(fd)))
			return (res);
		res->next = cur->next;
		cur->next = res;
	}
	return (res);
}

t_elem	*create_fd(int fd)
{
	t_elem	*res;

	if (!(res = (t_elem*)malloc(sizeof(t_elem))))
		return (NULL);
	res->fd = fd;
	res->next = res;
	res->str = ft_strnew(0);
	return (res);
}

t_elem	*del_fd(t_elem *cur)
{
	t_elem *crawler;

	if (cur->next == cur)
		crawler = NULL;
	else
	{
		crawler = cur->next;
		while (crawler && crawler->next != cur)
			crawler = crawler->next;
		crawler->next = cur->next;
	}
	free(cur);
	return (crawler);
}
