/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgwon <sgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 06:25:18 by sgwon             #+#    #+#             */
/*   Updated: 2025/12/02 03:01:38 by sgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*append(char *message, char c)
{
	char	*new_msg;
	size_t	size;

	if (!message)
	{
		new_msg = (char *)malloc(2);
		new_msg[0] = c;
		new_msg[1] = '\0';
		return (new_msg);
	}
	size = ft_strlen(message);
	new_msg = (char *)malloc(size + 2);
	ft_memcpy(new_msg, message, size);
	new_msg[size] = c;
	new_msg[size + 1] = '\0';
	free(message);
	return (new_msg);
}

void	handle_byte(char **message, char c, siginfo_t *info)
{
	if (c == '\0')
	{
		if (*message)
		{
			ft_printf("%s\n", *message);
			free(*message);
			*message = NULL;
		}
		kill(info->si_pid, SIGUSR2);
	}
	else
	{
		*message = append(*message, c);
		kill(info->si_pid, SIGUSR1);
	}
}

void	server_handler(int signum, siginfo_t *info, void *context)
{
	static int	current_byte = 0;
	static int	bit_idx = 0;
	static char	*message = NULL;

	(void)context;
	if (signum == SIGUSR1)
		current_byte |= 1 << bit_idx;
	bit_idx++;
	if (bit_idx == 8)
	{
		handle_byte(&message, current_byte, info);
		current_byte = 0;
		bit_idx = 0;
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
