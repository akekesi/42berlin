/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:43:28 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/05 09:43:28 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int argument)
{
	if ('a' <= argument && argument <= 'z')
		return (2);
	else if ('A' <= argument && argument <= 'Z')
		return (1);
	else
		return (0);
}
