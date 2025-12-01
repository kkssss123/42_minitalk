/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgwon <sgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:17:55 by sgwon             #+#    #+#             */
/*   Updated: 2025/10/08 13:45:49 by sgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*temp_dst;
	unsigned char	*temp_src;

	if (!src && !dest)
		return (NULL);
	i = 0;
	temp_dst = (unsigned char *)dest;
	temp_src = (unsigned char *)src;
	while (i < n)
	{
		if (src > dest)
			temp_dst[i] = temp_src[i];
		else
			temp_dst[n - 1 - i] = temp_src[n - 1 - i];
		i++;
	}
	return (dest);
}
