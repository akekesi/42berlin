/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:33:12 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/14 19:09:22 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_get_next_line_sub1(char **str_buff, char **str_line);
char	*ft_get_next_line_sub2(char **str_buff, char **str_line, int fd);
char	*ft_str_cat(char *str_line, char *str_buff);
void	ft_str_cat_sub(char *dest, char *src, int start);
int		ft_str_len(char *str);
int		ft_str_char(char *str, int c);
char	*ft_str_dup_b(char *str, int c);
char	*ft_str_dup_a(char *str, int c);
void	ft_str_free(char **str);

#endif
