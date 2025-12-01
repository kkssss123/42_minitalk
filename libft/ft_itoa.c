/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgwon <sgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:57:25 by sgwon             #+#    #+#             */
/*   Updated: 2025/11/11 14:29:37 by sgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	length(long long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len = 1;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long long	num;
	int			len;
	char		*str;

	num = (long long)n;
	len = length(num);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len--] = 0;
	if (n < 0)
		num *= -1;
	while (len >= 0)
	{
		str[len--] = num % 10 + '0';
		num /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
