/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:07:36 by akekesi           #+#    #+#             */
/*   Updated: 2023/08/20 14:22:44 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*message;
int		g_bit;
int		g_char;

void	signal_handler(int signal, siginfo_t *info, void *context)
{
	(void)context;
	if (signal == SIGUSR1)
	{
		char	c_bit;
		char	c_char;

		c_bit = g_bit + '0';
		c_char = g_char + '0';
		if (g_bit < 8)
		{
			str_put("sent the bit-");
			write(1, &c_char, 1);
			str_put("/");
			write(1, &c_bit, 1);
			str_put("-->\n");
			g_bit++;
		}
		if (g_bit == 8)
		{
			str_put("sent the char-");
			write(1, &c_char, 1);
			str_put("-->\n");
			g_char++;
			g_bit = 0;
			if (!message[g_char - 1])
			{
				str_put("sent last\n");
				exit(0);
			}
		}
		kill(info->si_pid, SIGUSR1);
	}
}

int	main(int argc, char **argv)
{
	pid_t				pid_server;
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	sigemptyset(&sa.sa_mask);

	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	if (argc == 3)
	{
		pid_server = atoi(argv[1]);
		message = argv[2];

		str_put("Message '");
		str_put(message);
		str_put("' is sent to the server\n");
		kill(pid_server, SIGUSR1);

		g_bit = 0;
		g_char = 0;
		while (1)
			pause();
	}
}
