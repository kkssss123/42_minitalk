/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgwon <sgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 13:04:10 by sgwon             #+#    #+#             */
/*   Updated: 2025/10/21 13:55:54 by sgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (len > s_len)
		len = s_len;
	if (start >= s_len)
		return (ft_strdup(""));
	if (s_len - start < len)
		str = (char *)malloc(s_len - start + 1);
	else
		str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, (char *)(s + start), len + 1);
	return (str);
}
