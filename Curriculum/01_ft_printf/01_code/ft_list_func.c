/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:50:55 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/28 17:53:00 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_func	*ft_list_func_new(char c, int (*f)(va_list));
t_func	*ft_list_func_last(t_func *list_func);
void	ft_list_func_add_last(t_func **list_func, t_func *new);
void	ft_list_func_new_add_last(t_func **list_func, char c, int (*f)(va_list));

t_func	*ft_list_func_new(char c, int (*f)(va_list))
{
	t_func	*new;

	new = (t_func *)malloc(sizeof(t_func) * 1);
	if (!new)
		return (NULL);
	new->c = c;
	new->f = f;
	new->next = NULL;
	return (new);
}

t_func	*ft_list_func_last(t_func *list_func)
{
	while (list_func->next)
		list_func = list_func->next;
	return (list_func);
}

void	ft_list_func_add_last(t_func **list_func, t_func *new)
{
	t_func	*last;

	if (!list_func)
		return ;
	if (!*list_func)
		*list_func = new;
	else
	{
		last = ft_list_func_last(*list_func);
		last->next = new;
	}
}

void	ft_list_func_new_add_last(t_func **list_func, char c, int (*f)(va_list))
{
	t_func	*new;

	new = ft_list_func_new(c, f);
	ft_list_func_add_last(list_func, new);
}

void ft_list_func_clear()
{

}

void ft_list_func_del()
{

}
