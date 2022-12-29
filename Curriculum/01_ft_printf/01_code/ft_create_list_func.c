/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_list_func.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:00:29 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/28 20:35:28 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "test.h"

t_func	**ft_create_list_func(void);
int		ft_write_char(va_list args);
int		ft_write_int(va_list args);

t_func	**ft_create_list_func(void)
{
	t_func	**list_func;
	t_func	*list_func_;

	list_func_ = ft_list_func_new('c', ft_write_char);
	printf("create list 0:\n");
	ft_list_func_print(list_func_);

	list_func = &list_func_;
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
