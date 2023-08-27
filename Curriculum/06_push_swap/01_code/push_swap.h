/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:07:54 by akekesi           #+#    #+#             */
/*   Updated: 2023/08/27 17:47:29 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_llist
{
	int				n;
	struct s_llist	*prev;
	struct s_llist	*next;
}	t_llist;

// llist_00.c
t_llist	*llist_create(int n);
void	llist_free(t_llist **head);

// llist_01.c
void	llist_add(t_llist **head, t_llist *node);
void	llist_rot(t_llist **head, int direction);
t_llist	*llist_del(t_llist **head);
void	llist_push(t_llist **head_a, t_llist **head_b);
void	llist_swap(t_llist **head);

// llist_02.c
int		llist_len(t_llist *head);
int		llist_pos(t_llist *head, int n);
int		llist_max_pos(t_llist *head);
int		llist_minmax_pos(t_llist *head, int n);


// llist_visualisation.c
void	llist_print(t_llist *list);

// sort_00.c


// ft*.c
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_isdigits(char *str);
int		ft_isspace(int c);
char	*ft_itoa(int n);
void	ft_putstr(char *str);

// push_swap_test.c
void	print_ab(t_llist *head_a, t_llist *head_b, int extra);
void	print_len(t_llist *head);
void	print_pos(t_llist *head, int n);

#endif
