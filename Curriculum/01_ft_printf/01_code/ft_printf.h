/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 15:17:09 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/04 01:11:55 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
int		ft_printf_sub(const char *str, va_list *args);
int		ft_print_call(va_list *args, int *flag_info);

int		ft_check_print(const char *str);

int		ft_print_char_flag(va_list *args, int *flag_info);
int		ft_print_str_flag(va_list *args, int *flag_info);
int		ft_print_hex_flag(va_list *args, int *flag_info);
int		ft_print_ptr_flag(va_list *args, int *flag_info);
int		ft_print_int_flag(va_list *args, int *flag_info);
int		ft_print_int_flag_sub(char *arg, int *flag_info, char *prefix);
int		ft_print_uint_flag(va_list *args, int *flag_info);
int		ft_print_flag_sub1(char *arg, char *prefix, int pad_a, int pad_b);
int		ft_print_flag_sub2(char *arg, char *prefix, int pad_a, int pad_b);
int		ft_print_flag_sub3(char *arg, char *prefix, int pad_a, int pad_b);
int		ft_print_flag_sub4(char *arg, char *prefix, int pad_a, int pad_b);
int		ft_print_flag_sub5(char *arg, char *prefix, int pad_a, int pad_b);

char	*ft_get_types(void);
char	*ft_get_flags(void);
char	*ft_get_null(char type);
char	*ft_get_prefix_main(int n, int prefix, int type, int pprefix);
char	*ft_get_prefix_ptr(char *arg, int *flag_info);
char	*ft_get_prefix_int(char *arg, int *flag_info);

int		ft_char_in_str(int c, const char *str);
int		*ft_flags_in_str(const char *str, int size, int *flag_info);
int		ft_int_in_str_dot_before(const char *str, int size);
int		ft_int_in_str_dot_after(const char *str, int size);

int		ft_is_digit(int c);
int		ft_is_first_int_zero(const char *str, int size);

int		ft_int_len(int n);
int		ft_uint_len(unsigned int n);
int		ft_ull_len(unsigned long long n);
int		ft_hex_len(unsigned int n);
int		ft_hexll_len(unsigned long long n);

int		ft_print_str(const char *str);
int		ft_print_char_n(int c, int size);

void	ft_set_int_zero(int *list, int size);

int		ft_str_len(const char *str);
char	*ft_str_cpy(char *dest, const char *src);
int		ft_str_cmp(const char *str1, const char *str2);
void	ft_str_to_upper(char *str);

char	*ft_char_to_str(int c);
char	*ft_str_to_str(char *str);
char	*ft_int_to_str(int n);
char	*ft_uint_to_str(unsigned int n);
char	*ft_ull_to_str(unsigned long long n);
char	*ft_hex_to_str(unsigned int n);
char	*ft_hex_to_str_sub(unsigned int n, char *arg, int size);
char	*ft_ptr_to_str(unsigned long long n);
char	*ft_ptr_to_str_sub(unsigned long long n);
int		ft_neg_to_zero(int n);

#endif
