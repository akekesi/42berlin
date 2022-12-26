/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:56:22 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/26 17:32:36 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	hf_char_in_set(char c, char const *set);
char		*ft_strtrim(char const *str, char const *set);

char	*ft_strtrim(char const *str, char const *set)
{
	int		start;
	int		end;
	char	*str_trim;

	if (!str || !set)
		return (NULL);
	start = 0;
	while (str[start] && hf_char_in_set(str[start], set))
		start++;
	end = ft_strlen(str);
	while (start < end && hf_char_in_set(str[end - 1], set))
		end--;
	str_trim = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!str_trim)
		return (NULL);
	str_trim = (char *)ft_memcpy(str_trim, str + start, end - start);
	str_trim[end - start] = '\0';
	return (str_trim);
}

static int	hf_char_in_set(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}
