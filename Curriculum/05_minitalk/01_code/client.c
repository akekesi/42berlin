/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:07:36 by akekesi           #+#    #+#             */
/*   Updated: 2023/08/18 18:36:24 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signal, siginfo_t *info, void *context)
{
	pid_t	pid_server;

	(void)context;
	pid_server = getppid();
	if (signal == SIGUSR1)
	{
		putstr("Client-S1\n");
		putstr("-->END<--\n");
		// kill(info->si_pid, SIGUSR1); // infinit loop
	}
	if (signal == SIGUSR2)
	{

		putstr("Client-S2\n");
		kill(info->si_pid, SIGUSR2);
	}
}

int	main(int argc, char **argv)
{
	pid_t				pid_server;
	char				*message;
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

		putstr("Message '");
		putstr(message);
		putstr("' is sent to the server\n");
		kill(pid_server, SIGUSR1);

		while (1)
			pause();
	}
}
