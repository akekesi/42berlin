/*
Assignment name  : ft_list_size
Expected files   : ft_list_size.c
Allowed functions: 
--------------------------------------------------------------------------------

Write a function that returns the number of elements in the linked list that's
passed to it.

It must be declared as follows:

int	ft_list_size(t_list *begin_list);

You must use the following structure in your program ft_list_size.c :

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	struct s_list	*next;
	void			*data;
}	t_list;

t_list	*ft_list_new(void)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list) * 1);
	if (!new)
		return (NULL);
	new->next = NULL;
	return (new);
}

int	ft_list_size(t_list *begin_list)
{
	if (!begin_list)
		return (0);
	return (ft_list_size(begin_list->next) + 1);
}

int	main(void)
{
	t_list	*begin_list;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	begin_list = NULL;
	printf("%d\n", ft_list_size(begin_list));
	node1 = ft_list_new();
	begin_list = node1;
	printf("%d\n", ft_list_size(begin_list));
	node2 = ft_list_new();
	node1->next = node2;
	printf("%d\n", ft_list_size(begin_list));
	node3 = ft_list_new();
	node2->next = node3;
	printf("%d\n", ft_list_size(begin_list));
	free(node1);
	free(node2);
	free(node3);
}
