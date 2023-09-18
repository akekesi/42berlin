/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:24:55 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/18 21:42:38 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "get_next_line_bonus.h"

typedef struct s_llist
{
	char			*line;
	struct s_llist	*prev;
	struct s_llist	*next;
}	t_llist;

// llist_00.c
t_llist	*llist_create(char *line);
void	llist_free(t_llist **head);
void	llist_add(t_llist **head, t_llist *node);
t_llist	*llist_del(t_llist **head);

// llist_01.c
void	llist_rot(t_llist **head);
void	llist_rrot(t_llist **head);
void	llist_print(t_llist *head);

// map.c
t_llist	*read_map(int fd);
void	prep_map(t_llist **map);

// ft*.c
void	ft_putstr(char *str);
char	*ft_strdup(char *str);
int		ft_strlen(const char *str);

#endif
