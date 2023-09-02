/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:07:54 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/02 23:47:11 by akekesi          ###   ########.fr       */
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

typedef struct s_moves
{
	int	a;
	int	b;
	int	ab;
	int	sum;
}	t_moves;

// push_swap.c with main
void	push_swap(int argc, char **argv);

// push_swap_bonus.c with main
void	push_swap_checker(int argc, char **argv);

// push_swap_util.c
int		fill_a(int argc, char **argv, t_llist **head_a);
void	execute_rule(t_llist **head_a, t_llist **head_b, char *rule);
void	execute_rule_sub_s(t_llist **head_a, t_llist **head_b, char *rule);
void	execute_rule_sub_p(t_llist **head_a, t_llist **head_b, char *rule);
void	execute_rule_sub_r(t_llist **head_a, t_llist **head_b, char *rule);

// push_swap_test.c
void	print_ab(t_llist *head_a, t_llist *head_b);
void	print_len(t_llist *head);
void	print_pos(t_llist *head, int n);
void	print_moves(t_moves moves);
void	test_get_moves(void);

// llist_00.c
t_llist	*llist_create(int n);
void	llist_free(t_llist **head);
void	llist_add(t_llist **head, t_llist *node);
t_llist	*llist_del(t_llist **head);

// llist_01.c
void	llist_rot(t_llist **head);
void	llist_rrot(t_llist **head);
void	llist_push(t_llist **head_a, t_llist **head_b);
void	llist_swap(t_llist **head);

// llist_02.c
int		llist_len(t_llist *head);
int		llist_pos(t_llist *head, int n);
int		llist_max_pos(t_llist *head);
int		llist_min_pos(t_llist *head);
int		llist_minmax_pos(t_llist *head, int n);

// llist_03.c
void	llist_print(t_llist *list);

// llist_04.c
int		llist_is_sorted(t_llist *list);
int		llist_is_unique(t_llist *list, int n);

// moves_00_get_set.c
void	get_moves(t_llist *head_a, t_llist *head_b, t_moves *moves);
void	set_moves(t_moves *moves, int a, int b);
void	cpy_moves(t_moves *moves_dst, t_moves *moves_src);
int		opt_move(int move, int len);

// moves_01_swap.c
void	sa(t_llist **head_a);
void	sb(t_llist **head_b);
void	ss(t_llist **head_a, t_llist **head_b);

// moves_02_push.c
void	pa(t_llist **head_a, t_llist **head_b);
void	pb(t_llist **head_a, t_llist **head_b);

// moves_03_rot.c
void	ra(t_llist **head_a);
void	rb(t_llist **head_b);
void	rr(t_llist **head_a, t_llist **head_b);

// moves_04_rrot.c
void	rra(t_llist **head_a);
void	rrb(t_llist **head_b);
void	rrr(t_llist **head_a, t_llist **head_b);

// moves_05_do.c
void	do_moves(t_llist **head_a, t_llist **head_b, t_moves *moves);
void	do_moves_sub_a(t_llist **head_a, t_moves *moves);
void	do_moves_sub_b(t_llist **head_b, t_moves *moves);
void	do_moves_sub_ab(t_llist **head_a, t_llist **head_b, t_moves *moves);

// sort_00.c
void	sort(t_llist **head_a, t_llist **head_b);
void	sort_3(t_llist **head);
void	sort_4(t_llist **head_a, t_llist **head_b);
void	sort_5(t_llist **head_a, t_llist **head_b);

// check_00.c
int		check_digits(char *str);
int		check_int(char *str);
int		check_pre(char *str);
int		check_rule(char *rule);
int		check_rule_extra(t_llist **head_a, t_llist **head_b, char *rule);

// ft*.c
int		ft_abs(int n);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_isdigits(char *str);
int		ft_isspace(int c);
char	*ft_itoa(int n);
void	ft_putstr(char *str);
int		ft_strcmp(const char *str1, const char *str2);
size_t	ft_strlen(const char *str);

#endif
