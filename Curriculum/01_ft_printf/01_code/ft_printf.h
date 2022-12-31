/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:49:14 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/31 17:11:53 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_printf_sub(const char *str, va_list *args);
int		ft_char_in_str(int c, char *str);
int		ft_char_in_str_n(int c, const char *str, int n);
int		ft_int_in_str(const char *str, int n);
int		ft_isdigit(int c);
int		ft_is_flag(const char *str);
int		ft_print_arg(int c, const char *str, int f, va_list *args);
int		ft_print_char(int c);
int		ft_print_str(char *str);
char	*ft_get_null(int c);
char	*ft_get_flags(void);
char	*ft_get_types(void);
int		ft_print_ptr(unsigned long long ptr);
int		ft_print_int(int n, int i);
int		ft_print_uint(unsigned int n, int i);
int		ft_print_hex(unsigned int n, int c, int i);
int		ft_print_uhex(unsigned long long n, int i);
int		ft_print_hex_flag(unsigned int arg, char c, const char *str, int f);
int		ft_print_int_flag(int arg, const char *str, int f);
int		ft_print_str_flag(char *arg, const char *str, int f);
int		ft_str_len(const char *str);
int		ft_print_pad(const char *str, int f, int len_arg);

#endif
