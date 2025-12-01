/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgwon <sgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:16:59 by sgwon             #+#    #+#             */
/*   Updated: 2025/12/01 08:23:00 by sgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	hex_length(unsigned int n)
{
	size_t	len;

	len = 1;
	while (n >= 16)
	{
		len++;
		n /= 16;
	}
	return (len);
}

static void	init(char *buf, unsigned int n, size_t i, char set[16])
{
	while (i--)
	{
		buf[i] = set[n % 16];
		n /= 16;
	}
}

ssize_t	print_hex(unsigned int n, char set[16])
{
	size_t	size;
	char	*buf;
	ssize_t	ret;

	size = hex_length(n);
	buf = (char *)malloc(size);
	if (!buf)
		return (-1);
	init(buf, n, size, set);
	ret = write(STDOUT_FILENO, buf, size);
	free(buf);
	return (ret);
}

ssize_t	print_xl(unsigned int n)
{
	return (print_hex(n, "0123456789abcdef"));
}

ssize_t	print_xu(unsigned int n)
{
	return (print_hex(n, "0123456789ABCDEF"));
}
