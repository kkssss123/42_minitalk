/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgwon <sgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 13:27:42 by sgwon             #+#    #+#             */
/*   Updated: 2025/10/22 15:36:43 by sgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	write_num(long long num, int fd)
{
	char		buf[11];
	char		temp[11];
	int			i;
	int			j;

	i = 0;
	if (num < 0)
	{
		buf[i++] = '-';
		num = -num;
	}
	if (num == 0)
		buf[i++] = '0';
	else
	{
		j = 0;
		while (num > 0)
		{
			temp[j++] = (num % 10) + '0';
			num /= 10;
		}
		while (j--)
			buf[i++] = temp[j];
	}
	write(fd, buf, i);
}

void	ft_putnbr_fd(int n, int fd)
{
	write_num(n, fd);
}
