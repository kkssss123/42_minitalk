/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgwon <sgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 12:34:24 by sgwon             #+#    #+#             */
/*   Updated: 2025/10/17 18:06:51 by sgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;
	size_t	b;

	if (size != 0 && nmemb > __INT_MAX__ / size)
		return (NULL);
	b = nmemb * size;
	p = malloc(b);
	if (!p)
		return (NULL);
	ft_bzero(p, b);
	return (p);
}
