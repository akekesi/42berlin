/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:36:15 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/28 20:35:08 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdlib.h>

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
t_func	**ft_create_list_func(void);
int		ft_write_char(va_list args);
int		ft_write_int(va_list args);

int		ft_printf(const char *str, ...);
char	*ft_types(void);
int		ft_check_next(const char *str);
int		ft_char_in_str(char c, char *str);
int		ft_strlen(const char *str);

#endif
