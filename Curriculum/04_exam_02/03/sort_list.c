/*
Assignment name  : sort_list
Expected files   : sort_list.c
Allowed functions: 
--------------------------------------------------------------------------------

Write the following functions:

t_list	*sort_list(t_list* lst, int (*cmp)(int, int));

This function must sort the list given as a parameter, using the function 
pointer cmp to select the order to apply, and returns a pointer to the 
first element of the sorted list.

Duplications must remain.

Inputs will always be consistent.

You must use the type t_list described in the file list.h 
that is provided to you. You must include that file 
(#include "list.h"), but you must not turn it in. We will use our own 
to compile your assignment.

Functions passed as cmp will always return a value different from 
0 if a and b are in the right order, 0 otherwise.

For example, the following function used as cmp will sort the list 
in ascending order:

int ascending(int a, int b)
{
	return (a <= b);
}
*/

#include <stdio.h>
#include <stdlib.h>
#include "sort_list.h"

int	ascending(int a, int b)
{
	return (a <= b);
}

t_list	*ft_list_new(int data)
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

t_list	*sort_list(t_list *begin, int (*cmp)(int, int))
{
	t_list	*tmp;
	t_list	*tmp_tmp;
	int		tmp_int;

	tmp_tmp = begin;
	while (tmp_tmp)
	{
		tmp = begin;
		while (tmp)
		{
			if (tmp->next)
			{
				if (!ascending(tmp->data, (tmp->next)->data))
				{
					tmp_int = tmp->data;
					tmp->data = (tmp->next)->data;
					(tmp->next)->data = tmp_int;
				}
			}
			tmp = tmp->next;
		}
		tmp_tmp = tmp_tmp->next;
	}
	return (begin);
}

void	ft_list_print(t_list *begin)
{
	t_list	*tmp;

	tmp = begin;
	while (tmp)
	{
		printf("%d\n", tmp->data);
		tmp = tmp->next;
	}
}

int	main(void)
{
	int		i = 0;
	int		n = 8;
	int		data[] = {13, -42, 99, 0, -1, 0, 1, -111};
	t_list	*node;
	t_list	*begin;
	t_list	*begin_sorted;

	begin = ft_list_new(42);
	i = 0;
	while (i < n)
	{
		node = ft_list_new(data[i]);
		ft_list_add_last(begin, node);
		i++;
	}
	ft_list_print(begin);
	begin_sorted = sort_list(begin, ascending);
	printf("\n");
	ft_list_print(begin_sorted);
}
