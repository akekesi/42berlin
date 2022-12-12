/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:08:37 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/12 11:08:37 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	size_t	i;
	char	c;
	char	*str_;

	i = 0;
	c = '\0';
	str_ = (char *)str;
	while (i < n)
	{
		str_[i] = c;
		i++;
	}
}
