/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgwon <sgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 06:25:18 by sgwon             #+#    #+#             */
/*   Updated: 2025/12/02 01:30:04 by sgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*merge_msg(char *msg, char bit)
{
	char	*new_msg;
	size_t	size;

	if (!msg)
	{
		new_msg = (char *)malloc(2);
		new_msg[0] = bit;
		new_msg[1] = '\0';
		return (new_msg);
	}
	size = ft_strlen(msg);
	new_msg = (char *)malloc(size + 2);
	ft_memcpy(new_msg, msg, size);
	new_msg[size] = bit;
	new_msg[size + 1] = '\0';
	free(msg);
	return (new_msg);
}

void	process_bit(char **msg, char bit, siginfo_t *info)
{
	if (bit == '\0')
	{
		if (*msg)
		{
			ft_printf("%s\n", *msg);
			free(*msg);
			*msg = NULL;
		}
		kill(info->si_pid, SIGUSR2);
	}
	else
	{
		*msg = merge_msg(*msg, bit);
		kill(info->si_pid, SIGUSR1);
	}
}

void	server_handler(int signum, siginfo_t *info, void *context)
{
	static int	bit = 0;
	static char	i = 0;
	static char	*msg = NULL;

	(void)context;
	if (signum == SIGUSR1)
		bit |= 1 << i;
	i++;
	if (i == 8)
	{
		process_bit(&msg, bit, info);
		bit = 0;
		i = 0;
	}
	else
		kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

	pid = getpid();
	ft_printf("PID: %d\n", (int)pid);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = server_handler;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
