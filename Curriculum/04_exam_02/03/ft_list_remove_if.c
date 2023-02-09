/*
Assignment name  : ft_list_remove_if
Expected files   : ft_list_remove_if.c
Allowed functions: free
--------------------------------------------------------------------------------

Write a function called ft_list_remove_if that removes from the
passed list any element the data of which is "equal" to the reference data.

It will be declared as follows :

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

cmp takes two void* and returns 0 when both parameters are equal.

You have to use the ft_list.h file, which will contain:

$>cat ft_list.h
typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;
$>
*/

#include <stdio.h>
#include <stdlib.h>
#include "ft_list_remove_if.h"

int	ft_data_cmp(void *data, void *data_ref)
{
	if (*(int *)data == *(int *)data_ref)
		return (0);
	return (1);
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

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*tmp;
	t_list	*tmp_prev;
	t_list	*tmp_free;

	if (!begin_list)
		return ;
	tmp = *begin_list;
	tmp_prev = NULL;
	while (tmp)
	{
		if (!cmp(data_ref, tmp->data))
		{
			if (!tmp_prev)
				*begin_list = tmp->next;
			else
				tmp_prev->next = tmp->next;
			tmp_free = tmp;
			tmp = tmp->next;
			free(tmp_free);
		}
		else
		{
			tmp_prev = tmp;
			tmp = tmp->next;
		}	
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
	ft_list_remove_if(&begin, (void *)&data_ref1, ft_data_cmp);
	printf("\n");
	ft_list_print(begin);
}
