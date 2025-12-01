/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgwon <sgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:00:32 by sgwon             #+#    #+#             */
/*   Updated: 2025/12/01 08:23:03 by sgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	hex_length(unsigned long long n)
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

static void	init(char *buf, unsigned long long n, size_t i)
{
	while (i--)
	{
		buf[i] = "0123456789abcdef"[n % 16];
		n /= 16;
	}
}

ssize_t	print_p(unsigned long long n)
{
	size_t	size;
	char	*buf;
	ssize_t	ret;

	if (n == 0)
		return (write(STDOUT_FILENO, "(nil)", 5));
	size = hex_length(n) + 2;
	buf = (char *)malloc(size);
	if (!buf)
		return (-1);
	ft_memcpy(buf, "0x", 2);
	init(buf + 2, n, size - 2);
	ret = write(STDOUT_FILENO, buf, size);
	free(buf);
	return (ret);
}
