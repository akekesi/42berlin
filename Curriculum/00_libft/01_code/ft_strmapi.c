/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 19:03:43 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/25 20:20:11 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	n;
	char			*str_new;

	if (!str)
		return (NULL);
	n = ft_strlen(str);
	str_new = (char *)malloc(sizeof(char) * (n + 1));
	if (!str_new)
		return (NULL);
	i = 0;
	while (i < n)
	{
		str_new[i] = f(i, str[i]);
		i++;
	}
	str_new[i] = '\0';
	return (str_new);
}
