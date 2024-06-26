/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:07:54 by akekesi           #+#    #+#             */
/*   Updated: 2023/08/21 21:50:25 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_isdigits(char *str);
int		ft_isspace(int c);
char	*ft_itoa(int n);
void	ft_putstr(char *str);

typedef struct s_info
{
	int		first;
	int		n_bit;
	int		n_char;
	int		l_message;
	char	char_;
	char	*message;
}	t_info;

#endif
