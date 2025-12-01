/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgwon <sgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:16:59 by sgwon             #+#    #+#             */
/*   Updated: 2025/12/01 08:23:06 by sgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	print_c(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

ssize_t	print_s(char *s)
{
	if (!s)
		return (write(STDOUT_FILENO, "(null)", 6));
	return (write(STDOUT_FILENO, s, ft_strlen(s)));
}

ssize_t	print_pc(void)
{
	return (print_c('%'));
}
