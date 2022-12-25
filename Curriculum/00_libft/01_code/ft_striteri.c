/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 19:03:43 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/25 21:04:43 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *str, void (f)(unsigned int, char*))
{
	unsigned int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		f(i, &str[i]);
		i++;
	}
}
