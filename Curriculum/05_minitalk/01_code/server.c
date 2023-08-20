/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:07:33 by akekesi           #+#    #+#             */
/*   Updated: 2023/08/20 19:59:32 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_info	g_info;

void	signal_handler(int signal, siginfo_t *info, void *context)
{
	char	c_bit;
	char	c_char;

	(void)context;
	if (g_info.first)
	{
		kill(info->si_pid, SIGUSR1);
		g_info.first = 0;
		return ;
	}
	c_bit = g_info.n_bit + '0';
	c_char = g_info.n_char + '0';
	if (g_info.n_bit < 8)
	{
		if (signal == SIGUSR1)
			g_info.char_ = (g_info.char_ << 1) | 1;
		if (signal == SIGUSR2)
			g_info.char_ = (g_info.char_ << 1) | 0;
		ft_putstr("got the bit-");
		write(1, &c_char, 1);
		ft_putstr("/");
		write(1, &c_bit, 1);
		ft_putstr("\n");
		g_info.n_bit++;
	}
	if (g_info.n_bit == 8)
	{
		if (!g_info.char_)
		{
			ft_putstr("got last\n");
			g_info.n_char = 0;
			g_info.n_bit = 0;
			g_info.char_ = 0;
			g_info.first = 1;
			return ;
		}
		ft_putstr("got the char----->");
		write(1, &g_info.char_, 1);
		ft_putstr("<-----\n");
		g_info.n_char++;
		g_info.n_bit = 0;
		g_info.char_ = 0;
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

	ft_putstr("server pid: ");
	ft_putstr(ft_itoa(getpid()));
	ft_putstr("\n");

	g_info.first = 1;
	g_info.n_bit = 0;
	g_info.n_char = 0;
	g_info.char_ = 0;
	while (1)
		pause();
}
