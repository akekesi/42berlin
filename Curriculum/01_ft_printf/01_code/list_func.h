/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_func.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 10:26:16 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/30 10:26:16 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_FUNC_H
# define LIST_FUNC_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_func
{
	char			c;
	int				(*f)(va_list);
	struct s_func	*next;
}	t_func;

t_func	*ft_list_func_new(char c, int (*f)(va_list));
t_func	*ft_list_func_last(t_func *list_func);
void	ft_list_func_add_last(t_func **list_func, t_func *new);
void	ft_list_func_new_add_last(t_func **list_func, char c, int (*f)(va_list));
void	ft_list_func_del(t_func *list_func);
void	ft_list_func_clear(t_func **list_func);
void	ft_list_func_print(t_func *list_func);
t_func	*ft_create_list_func(void);
int		ft_write_char(va_list args);
int		ft_write_int(va_list args);

#endif
