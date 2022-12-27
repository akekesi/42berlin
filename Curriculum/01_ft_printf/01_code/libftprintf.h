/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:36:15 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/27 23:03:06 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>

int		ft_printf(const char *str, ...);
char	*ft_types(void);
int		ft_check_next(const char *str);
int		ft_char_in_str(char c, char *str);
int		ft_strlen(const char *str);

#endif
