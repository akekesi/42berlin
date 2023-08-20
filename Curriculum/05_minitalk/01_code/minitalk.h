/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:07:54 by akekesi           #+#    #+#             */
/*   Updated: 2023/08/20 17:34:03 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>	// DELETE: only for atoi
# include <stdio.h>	    // DELETE: only for printf

void	itoa_pos(int n);
void	str_put(char *str);
int	    str_len(char *str);

typedef struct s_info
{
    int		first;
    int		n_bit;
    int		n_char;
    char	char_;
    char	*message;
}						t_info;

#endif
