/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:07:33 by akekesi           #+#    #+#             */
/*   Updated: 2023/08/20 14:22:47 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_bit;
int	g_char;

void	signal_handler(int signal, siginfo_t *info, void *context)
{
	char	c_bit;
	char	c_char;

	(void)context;
	(void)signal;
	c_bit = g_bit + '0';
	c_char = g_char + '0';
	if (g_bit < 8)
	{
		str_put("got the bit-");
		write(1, &c_char, 1);
		str_put("/");
		write(1, &c_bit, 1);
		str_put("\n");
		g_bit++;
	}
	if (g_bit == 8)
	{
		str_put("got the char-");
		write(1, &c_char, 1);
		str_put("\n");
		g_char++;
		g_bit = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
	{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	sigemptyset(&sa.sa_mask);

	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	str_put("server pid: ");
	itoa_pos(getpid());
	str_put("\n");

	g_bit = 0;
	g_char = 0;
	while (1)
		pause();
}
