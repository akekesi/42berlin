/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:49:14 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/30 14:49:29 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
char	*ft_types(void);
int		ft_char_in_str(int c, char *str);
int		ft_print_arg(int c, va_list *args);
int		ft_print_char(int c);
int		ft_print_str(char *str);
int		ft_print_ptr(unsigned long long ptr);
int		ft_print_int(int n, int i);
int		ft_print_uint(unsigned int n, int i);
int		ft_print_hex(unsigned int n, int c, int i);
int		ft_print_uhex(unsigned long long n, int i);

#endif
