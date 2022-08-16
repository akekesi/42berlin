/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 18:07:19 by akekesi           #+#    #+#             */
/*   Updated: 2022/08/12 18:07:19 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include <stdlib.h>

typedef struct s_list
{
	struct s_list	*next;
	void			*data;
}	t_list;

t_list	*ft_create_elem(void *data);
t_list	*ft_list_last(t_list *begin_list);
t_list	*ft_list_at(t_list *begin_list, unsigned int nbr);
void	ft_list_push_back(t_list **begin_list, void *data);
void	ft_list_print(t_list *being_list);

#endif
