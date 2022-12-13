/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:00:08 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/13 15:28:27 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_isalnum(int c);
static int	hf_ft_isdigit(int c);
static int	hf_ft_isalpha(int c);

int	ft_isalnum(int c)
{
	if (hf_ft_isalpha(c) || hf_ft_isdigit(c))
		return (1);
	return (0);
}

static int	hf_ft_isalpha(int c)
{
	if ('a' <= c && c <= 'z')
		return (2);
	else if ('A' <= c && c <= 'Z')
		return (1);
	else
		return (0);
}

static int	hf_ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}
