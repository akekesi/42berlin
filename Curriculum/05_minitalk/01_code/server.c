/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:07:33 by akekesi           #+#    #+#             */
/*   Updated: 2023/08/13 22:15:56 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sigusr1_handler(int signum)
{
	(void) signum;
	write(1, "S1\n", 3);
}

void	sigusr2_handler(int signum)
{
	(void) signum;
	write(1, "S2\n", 3);
}

int	main(void)
{
	char	c;
	pid_t	pid;

	pid = getpid();
	while (pid)
	{
		c = pid % 10 + '0';
		write(1, &c, 1);
		pid /= 10;
	}
	write(1, "<--backwards\n", 13);
	signal(SIGUSR2, sigusr2_handler);
	signal(SIGUSR1, sigusr1_handler);
	while (1)
	{
		pause();
	}
}
