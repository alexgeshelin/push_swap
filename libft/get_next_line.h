/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohesheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 19:11:21 by ohesheli          #+#    #+#             */
/*   Updated: 2017/01/23 19:12:17 by ohesheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# define BUFF_SIZE 32
# define SIZE_LINE ft_strchr(*rem, '\n') - *rem
# define SIZE_REST ft_strchr(*rem, '\0') - ft_strchr(*rem, '\n')
# define SIZE_LAST ft_strchr(*rem, '\0') - *rem

typedef struct	s_elem
{
	char			*str;
	int				fd;
	struct s_elem	*next;
}				t_elem;

int				get_next_line(const int fd, char **line);
int				get_line(char **rem, char **line);
t_elem			*get_fd(t_elem *cur, int fd);
t_elem			*create_fd(int fd);
t_elem			*del_fd(t_elem *cur);

#endif
