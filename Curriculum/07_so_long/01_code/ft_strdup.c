/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:36:06 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/18 22:01:16 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(char *str)
{
	int		i;
	char	*str_dup;

	if (!str)
		return (NULL);
	i = ft_strlen(str);
	str_dup = (char *)malloc(sizeof(char) * (i + 1));
	if (!str_dup)
		return (NULL);
	while (-1 < i)
	{
		str_dup[i] = str[i];
		i--;
	}
	return (str_dup);
}
