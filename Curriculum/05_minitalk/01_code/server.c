/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:07:33 by akekesi           #+#    #+#             */
/*   Updated: 2023/08/24 19:06:29 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signal, siginfo_t *info, void *context);
void	signal_handler_sub1(int signal);
void	signal_handler_sub2(void);

t_info	g_info;

void	signal_handler(int signal, siginfo_t *info, void *context)
{
	(void)context;
	if (g_info.first)
	{
		kill(info->si_pid, SIGUSR1);
		g_info.first = 0;
		return ;
	}
	if (g_info.n_bit < 8)
		signal_handler_sub1(signal);
	if (g_info.n_bit == 8)
	{
		if (!g_info.char_)
		{
			signal_handler_sub2();
			return ;
		}
		write(1, &g_info.char_, 1);
		g_info.l_message++;
		g_info.n_char++;
		g_info.n_bit = 0;
		g_info.char_ = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

void	signal_handler_sub1(int signal)
{
	if (signal == SIGUSR1)
		g_info.char_ = (g_info.char_ << 1) | 1;
	if (signal == SIGUSR2)
		g_info.char_ = (g_info.char_ << 1) | 0;
	g_info.n_bit++;
}

void	signal_handler_sub2(void)
{
	char	*l_message_str;

	l_message_str = ft_itoa(g_info.l_message);
	ft_putstr("\ngot last\n");
	ft_putstr("length of received message: ");
	ft_putstr(l_message_str);
	ft_putstr("\n");
	free(l_message_str);
	g_info.first = 1;
	g_info.n_char = 0;
	g_info.n_bit = 0;
	g_info.l_message = 0;
	g_info.char_ = 0;
}

int	main(void)
	{
	struct sigaction	sa;
	char				*pid_server_str;

	pid_server_str = ft_itoa(getpid());
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putstr("server pid: ");
	ft_putstr(pid_server_str);
	ft_putstr("\n");
	free(pid_server_str);
	g_info.first = 1;
	g_info.n_bit = 0;
	g_info.n_char = 0;
	g_info.char_ = 0;
	g_info.l_message = 0;
	while (1)
		pause();
}
