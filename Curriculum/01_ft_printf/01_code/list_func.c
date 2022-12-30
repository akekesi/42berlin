/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 10:29:38 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/30 10:29:38 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_func.h"

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

void	ft_list_func_del(t_func *list_func)
{
	if (!list_func)
		return ;
	free(list_func);
}

void	ft_list_func_clear(t_func **list_func)
{
	t_func	*tmp;

	if (!list_func)
		return ;
	printf("clear:\n");
	while (*list_func)
	{
		tmp = *list_func;
		*list_func = (*list_func)->next;
		ft_list_func_del(tmp);
	}
}

void	ft_list_func_print(t_func *list_func)
{
	printf("-------------\n");
	while (list_func)
	{
		printf("%p\n", list_func);
		printf("c:    %c\n", list_func->c);
		printf("f:    %p\n", list_func->f);
		printf("next: %p\n", list_func->next);
		list_func = list_func->next;
	}
	printf("-------------\n");
}

t_func	*ft_create_list_func(void)
{
	t_func	*list_func;

	list_func = ft_list_func_new('c', ft_write_char);
	printf("create list 0:\n");
	ft_list_func_print(list_func);

	ft_list_func_new_add_last(&list_func, 'i', ft_write_int);
	printf("create list 2:\n");
	ft_list_func_print(list_func);

	ft_list_func_new_add_last(&list_func, 'c', ft_write_char);
	printf("create list 3:\n");
	ft_list_func_print(list_func);

	return (list_func);
}

int	ft_write_char(va_list args)
{
	if (args)
		return (1);
	return (0);
}

int	ft_write_int(va_list args)
{
	if (args)
		return (1);
	return (0);
}

// int	main (void)
// {
// 	t_func	*list_func;

// 	printf("|-- test list_func -->\n");
// 	list_func = ft_create_list_func();
// 	ft_list_func_print(list_func);
// 	ft_list_func_print(list_func);
// 	ft_list_func_clear(&list_func);
// 	ft_list_func_print(list_func);
// 	ft_list_func_print(list_func);
// 	printf("<-- test list_func --|\n");
// }
