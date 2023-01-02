/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 15:17:09 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/01 15:17:09 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
int		ft_print_call(va_list *args, const char *str, int t);
int		ft_print_pad(int c, int n);

int		ft_print_char_flag(va_list *args, const char *str, int t);
int		ft_print_str_flag(va_list *args, const char *str, int t);
int		ft_print_ptr_flag(va_list *args, const char *str, int t);
int		ft_print_int_flag(va_list *args, const char *str, int t);
int		ft_print_uint_flag(va_list *args, const char *str, int t);
int		ft_print_hex_flag(va_list *args, const char *str, int t);

int		ft_print_str(const char *str);
int		ft_print_pad_pos(char *arg, const char *str, int t, int c);

char	*ft_char_to_str(int c);
char	*ft_str_to_str(char *str);

char	*ft_get_types(void);
char	*ft_get_flags(void);
char	*ft_get_null(char type);

int		ft_check_print(const char *str);

int		ft_char_in_str(int c, const char *str);
int		ft_char_in_str_n(int c, const char *str, int n);
int		ft_int_in_str(const char *str, int n);

int		ft_is_digit(int c);

int		ft_str_len(const char *str);

#endif
