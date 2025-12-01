/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgwon <sgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:17:55 by sgwon             #+#    #+#             */
/*   Updated: 2025/11/10 16:15:14 by sgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	slen;
	size_t	i;
	size_t	j;
	size_t	dlen;

	slen = ft_strlen(src);
	i = 0;
	j = 0;
	while (i < size && dst[i])
		i++;
	dlen = i;
	while (i + 1 < size && src[j])
		dst[i++] = src[j++];
	if (i < size)
		dst[i] = '\0';
	return (dlen + slen);
}
