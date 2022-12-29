/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:50:55 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/28 20:35:23 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "test.h"

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
		// ft_list_func_print(tmp);
		ft_list_func_del(tmp);
	}
}

void	ft_list_func_print(t_func *list_func)
{
	// t_func	*tmp;

	printf("-------------\n");
	// tmp = list_func;
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

t_func	**ft_create_list_func(void)
{
	t_func	**list_func;
	t_func	*list_func_first;

	list_func_first = ft_list_func_new('c', ft_write_char);
	printf("create list 0:\n");
	ft_list_func_print(list_func_first);

	list_func = &list_func_first;
	printf("create list 1:\n");
	ft_list_func_print(*list_func);

	ft_list_func_new_add_last(list_func, 'i', ft_write_int);
	printf("create list 2:\n");
	ft_list_func_print(*list_func);

	ft_list_func_new_add_last(list_func, 'c', ft_write_char);
	printf("create list 3:\n");
	ft_list_func_print(*list_func);

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

// https://pythontutor.com/visualize.html?fbclid=IwAR3Z79goHdPJypq8MU8o9On1Srd_YMX-714PAEnrhtHMSitv_t_1xjT26d4#code=%23include%20%3Cstdio.h%3E%0A%0Atypedef%20struct%20s_list%20%7B%0A%20%20struct%20s_list*%20next%3B%0A%20%20int%20val%3B%0A%7D%20t_list%3B%0A%0At_list%20%20*ft_lstnew%28void%29%0A%7B%0A%20%20%20%20t_list%20%20%20%20*new%3B%0A%0A%20%20%20%20new%20%3D%20%28t_list%20*%29malloc%28sizeof%28t_list%29%20*%201%29%3B%0A%20%20%20%20if%20%28!new%29%0A%20%20%20%20%20%20%20%20return%20%280%29%3B%0A%20%20%20%20new-%3Eval%20%3D%201%3B%0A%20%20%20%20new-%3Enext%20%3D%200%3B%0A%20%20%20%20return%20%28new%29%3B%0A%7D%0A%0Aint%20%20%20%20ft_lstsize%28t_list%20*lst%29%0A%7B%0A%20%20%20%20int%20%20%20%20%20%20%20%20i%3B%0A%0A%20%20%20%20i%20%3D%200%3B%0A%20%20%20%20while%20%28lst%29%0A%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20i%2B%2B%3B%0A%20%20%20%20%20%20%20%20lst%20%3D%20lst-%3Enext%3B%0A%20%20%20%20%7D%0A%20%20%20%20return%20%28i%29%3B%0A%7D%0A%0Aint%20main%28%29%0A%7B%0A%20%20t_list%20*list1%3B%0A%20%20t_list%20*list2%3B%0A%20%20%0A%20%20list1%20%3D%20ft_lstnew%28%29%3B%0A%20%20list2%20%3D%20ft_lstnew%28%29%3B%0A%20%20list1-%3Enext%20%3D%20list2%3B%0A%20%20printf%28%22%25d%5Cn%22,ft_lstsize%28list1%29%29%3B%0A%20%20printf%28%22%25d%5Cn%22,ft_lstsize%28list2%29%29%3B%0A%7D&cumulative=false&heapPrimitives=nevernest&mode=edit&origin=opt-frontend.js&py=c_gcc9.3.0&rawInputLstJSON=%5B%5D&textReferences=false