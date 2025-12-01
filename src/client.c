/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgwon <sgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 06:26:12 by sgwon             #+#    #+#             */
/*   Updated: 2025/12/02 02:02:31 by sgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_ack;

void	client_handler(int signum)
{
	g_ack = 1;
	if (signum == SIGUSR2)
		ft_printf("Ack from server\n");
}

void	try_kill(int pid, int signum)
{
	if (kill(pid, signum) < 0)
	{
		ft_printf("[ERROR] kill() failed: invalid PID or signal\n");
		exit(1);
	}
}

void	send(int pid, char bit)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		g_ack = 0;
		if (bit & (1 << i))
			try_kill(pid, SIGUSR1);
		else
			try_kill(pid, SIGUSR2);
		while (!g_ack)
			usleep(100);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc != 3)
	{
		ft_printf("Usage: ./client <PID> <message>\n");
		exit(1);
	}
	pid = ft_atoi(argv[1]);
	i = 0;
	signal(SIGUSR1, client_handler);
	signal(SIGUSR2, client_handler);
	while (argv[2][i])
		send(pid, argv[2][i++]);
	send(pid, '\0');
}
