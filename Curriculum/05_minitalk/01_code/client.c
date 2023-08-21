/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:07:36 by akekesi           #+#    #+#             */
/*   Updated: 2023/08/21 20:17:57 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_info	g_info;

void	signal_handler(int signal, siginfo_t *info, void *context)
{
	(void)context;
	g_info.first = 0;
	if (signal == SIGUSR1)
	{
		if (g_info.n_bit < 8)
		{
			if ((g_info.message[g_info.n_char] >> (7 - g_info.n_bit)) & 1)
				kill(info->si_pid, SIGUSR1);
			else
				kill(info->si_pid, SIGUSR2);
			g_info.n_bit++;
		}
		if (g_info.n_bit == 8)
		{
			if (!g_info.message[g_info.n_char])
			{
				ft_putstr("sent last\n");
				ft_putstr("length of sent message: ");
				ft_putstr(ft_itoa(g_info.l_message));
				ft_putstr("\n");
				exit(0);
			}
			g_info.n_bit = 0;
			g_info.n_char++;
			g_info.l_message++;
		}
	}
}

int	check_args(int argc, char **argv)
{
	int	n;

	if (argc != 3)
	{
		ft_putstr("ERROR: argc != 3");
		return (0);
	}
	n = ft_atoi(argv[1]);
	if (n < 0)
	{
		ft_putstr("ERROR: pid < 0");
		return (0);
	}
	if (n == 0)
	{
		ft_putstr("ERROR: pid == 0");
		return (0);
	}
	if (!ft_isdigits(argv[1]))
	{
		ft_putstr("ERROR: invalid pid");
		return (0);
	}
	return (1);
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
	if (check_args(argc, argv))
	{
		pid_server = (pid_t)ft_atoi(argv[1]);
		g_info.message = argv[2];
		g_info.first = 1;
		g_info.n_bit = 0;
		g_info.n_char = 0;
		g_info.l_message = 0;
		ft_putstr(g_info.message);
		ft_putstr("\nmessage is sent to the server-");
		ft_putstr(ft_itoa(pid_server));
		ft_putstr("\n");
		kill(pid_server, SIGUSR1);
		while (1)
		{
			sleep(3);
			if (g_info.first == 1)
			{
				ft_putstr("ERROR: no feedback");
				exit(0);
			}
		}
	}
}

/*
// main to test with very long message
// message: n times argv[2] if argv[2] < 150.000

# include <string.h>

int	main(int argc, char **argv)
{
	int					n = 10;
	char				result[n * 150000];
	pid_t				pid_server;
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_handler;

	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	if (check_args(argc, argv))
	{
		strcpy(result, argv[2]);
		while (--n)
			strcat(result, argv[2]);
		pid_server = (pid_t)ft_atoi(argv[1]);
		g_info.message = result;
		g_info.first = 1;
		g_info.n_bit = 0;
		g_info.n_char = 0;
		g_info.l_message = 0;

		ft_putstr(g_info.message);
		ft_putstr("\nmessage is sent to the server-");
		ft_putstr(ft_itoa(pid_server));
		ft_putstr("\n");
		kill(pid_server, SIGUSR1);

		while (1)
		{
			sleep(3);
			if (g_info.first == 1)
			{
				ft_putstr("ERROR: no feedback");
				exit(0);
			}
		} 
	}
}
*/