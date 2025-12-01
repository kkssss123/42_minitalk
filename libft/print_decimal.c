/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgwon <sgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:16:59 by sgwon             #+#    #+#             */
/*   Updated: 2025/12/02 03:02:02 by sgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	print_di(int n)
{
	char	*buf;
	ssize_t	ret;

	buf = ft_itoa(n);
	if (!buf)
		return (-1);
	ret = write(STDOUT_FILENO, buf, ft_strlen(buf));
	free(buf);
	return (ret);
}

static size_t	length(unsigned int n)
{
	size_t	len;

	len = 1;
	while (n >= 10)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static void	init(char *buf, unsigned int n, size_t i)
{
	while (i--)
	{
		buf[i] = n % 10 + '0';
		n /= 10;
	}
}

ssize_t	print_u(unsigned int n)
{
	size_t	size;
	char	*buf;
	ssize_t	ret;

	size = length(n);
	buf = (char *)malloc(size);
	if (!buf)
		return (-1);
	init(buf, n, size);
	ret = write(STDOUT_FILENO, buf, size);
	free(buf);
	return (ret);
}
