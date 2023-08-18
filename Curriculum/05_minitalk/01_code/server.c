/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:07:33 by akekesi           #+#    #+#             */
/*   Updated: 2023/08/18 18:36:48 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signal, siginfo_t *info, void *context)
{
	pid_t	client_pid;

	(void)context;
	client_pid = getppid();
	if (signal == SIGUSR1)
	{

		putstr("Server-S1\n");
		kill(info->si_pid, SIGUSR2);
	}
	if (signal == SIGUSR2)
	{

		putstr("Server-S2\n");
		kill(info->si_pid, SIGUSR1);
	}
}

int	main(void)
	{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	sigemptyset(&sa.sa_mask);

	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	putstr("server pid: ");
	itoa_pos(getpid());
	putstr("\n");
	while (1)
		pause();
}
