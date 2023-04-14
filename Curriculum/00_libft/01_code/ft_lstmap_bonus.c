/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 12:12:07 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/26 17:20:47 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*elem;
	t_list	*lst_new;
	void	*tmp_content;

	if (!f || !del)
		return (NULL);
	lst_new = NULL;
	while (lst)
	{
		tmp_content = f(lst->content);
		elem = ft_lstnew(tmp_content);
		if (!elem)
		{
			del(tmp_content);
			ft_lstclear(&lst_new, del);
			return (NULL);
		}
		ft_lstadd_back(&lst_new, elem);
		lst = lst->next;
	}
	return (lst_new);
}
