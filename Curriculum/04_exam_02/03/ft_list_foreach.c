/*
Assignment name  : ft_list_foreach
Expected files   : ft_list_foreach.c, ft_list.h
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a list and a function pointer, and applies this
function to each element of the list.

It must be declared as follows:

void    ft_list_foreach(t_list *begin_list, void (*f)(void *));

The function pointed to by f will be used as follows:

(*f)(list_ptr->data);

You must use the following structure, and turn it in as a file called
ft_list.h:

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;
*/

#include <stdio.h>
#include <stdlib.h>
#include "ft_list_foreach.h"

void	ft_data_2x(void *data)
{
	*(int *)data *= 2;
}

t_list	*ft_list_new(void *data)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list) * 1);
	if (!node)
		return (NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}

t_list	*ft_list_last(t_list *begin)
{
	t_list	*last;

	last = begin;
	while (last->next)
		last = last->next;
	return (last);
}

void	ft_list_add_last(t_list *begin, t_list *node)
{
	t_list	*last;

	last = ft_list_last(begin);
	last->next = node;
}

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list	*tmp;

	tmp = begin_list;
	while (tmp)
	{
		f(tmp->data);
		tmp = tmp->next;
	}
}

void	ft_list_print(t_list *begin)
{
	t_list	*tmp;

	tmp = begin;
	while (tmp)
	{
		printf("data=%d, %p --> %p\n", *(int *) tmp->data, tmp, tmp->next);
		tmp = tmp->next;
	}
}

int	main(void)
{
	int		i = 0;
	int		n = 6;
	int		data[] = {1, 2, 3, 4, 5, 0};
	int		data_ref1 = 3;
	t_list	*node;
	t_list	*begin;

	begin = ft_list_new(&data_ref1);
	i = 0;
	while (i < n)
	{
		node = ft_list_new(&data[i]);
		ft_list_add_last(begin, node);
		i++;
	}
	ft_list_print(begin);
	ft_list_foreach(begin, ft_data_2x);
	printf("\n");
	ft_list_print(begin);
}
