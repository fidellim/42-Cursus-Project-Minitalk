/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flim <flim@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 00:22:34 by flim              #+#    #+#             */
/*   Updated: 2022/02/27 11:05:58 by flim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	print_conversion(va_list args, const char c)
{
	int	str_count;

	str_count = 1;
	if (c == 'c')
		str_count = print_char(args);
	else if (c == 's')
		str_count = print_str(args);
	else if (c == 'p')
		str_count = print_pointer(args);
	else if (c == 'd' || c == 'i')
		str_count = print_int(args);
	else if (c == 'u')
		str_count = print_uint(args);
	else if (c == 'x' || c == 'X')
		str_count = print_hex(args, c);
	else if (c == '%')
		ft_putchar_fd('%', 1);
	else
		str_count = 0;
	return (str_count);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		str_count;

	str_count = 0;
	va_start(args, s);
	while (*s)
	{
		if (*s == '%')
			str_count += print_conversion(args, *++s);
		else
		{
			ft_putchar_fd(*s, 1);
			str_count++;
		}
		if (*s)
			s++;
	}
	va_end(args);
	return (str_count);
}
