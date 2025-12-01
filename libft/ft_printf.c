/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgwon <sgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 12:15:54 by sgwon             #+#    #+#             */
/*   Updated: 2025/12/01 08:23:10 by sgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	check_and_init(const char *format, size_t *cur, ssize_t *total)
{
	if (!format)
		return (0);
	*cur = 0;
	*total = 0;
	return (1);
}

static size_t	get_next_percent(const char *format, size_t cur)
{
	while (format[cur] && format[cur] != '%')
		cur++;
	return (cur);
}

static ssize_t	print_literal(const char *format, size_t len, ssize_t *total)
{
	ssize_t	n;

	n = write(STDOUT_FILENO, format, len);
	if (n > 0)
		*total += n;
	return (n);
}

static ssize_t	print_specifier(
	const char *format, size_t *i, va_list *args, ssize_t *total)
{
	char	c;
	ssize_t	len;

	if (format[(*i)++] != '%')
		return (-1);
	len = -1;
	c = format[(*i)++];
	if (c == 'c')
		len = print_c((char)va_arg(*args, int));
	else if (c == 's')
		len = print_s(va_arg(*args, char *));
	else if (c == 'p')
		len = print_p(va_arg(*args, unsigned long long));
	else if (c == 'd' || c == 'i')
		len = print_di(va_arg(*args, int));
	else if (c == 'u')
		len = print_u(va_arg(*args, unsigned int));
	else if (c == 'x')
		len = print_xl(va_arg(*args, unsigned int));
	else if (c == 'X')
		len = print_xu(va_arg(*args, unsigned int));
	else if (c == '%')
		len = print_pc();
	*total += len;
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	cur;
	size_t	next;
	ssize_t	total;

	va_start(args, format);
	if (!check_and_init(format, &cur, &total))
		return (-1);
	while (1)
	{
		next = get_next_percent(format, cur);
		if (print_literal(format + cur, next - cur, &total) < 0)
			return (-1);
		if (!format[next])
			break ;
		if (print_specifier(format, &next, &args, &total) < 0)
			return (-1);
		cur = next;
	}
	va_end(args);
	return (total);
}
