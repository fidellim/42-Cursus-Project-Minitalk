/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flim <flim@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 12:06:18 by flim              #+#    #+#             */
/*   Updated: 2022/02/27 00:38:57 by flim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_puthex(unsigned int n, char c)
{
	int		n_count;
	char	*hex_base;

	n_count = 1;
	if (c == 'x')
		hex_base = "0123456789abcdef";
	else
		hex_base = "0123456789ABCDEF";
	if (n > 15)
		n_count += ft_puthex(n / 16, c);
	ft_putchar_fd(hex_base[n % 16], 1);
	return (n_count);
}

static int	ft_putpointer(unsigned long n)
{
	int		n_count;
	char	*hex_base;

	n_count = 1;
	hex_base = "0123456789abcdef";
	if (n > 15)
		n_count += ft_putpointer(n / 16);
	ft_putchar_fd(hex_base[n % 16], 1);
	return (n_count);
}

int	print_hex(va_list args, char c)
{
	unsigned int	n;
	int				n_count;

	n = va_arg(args, unsigned int);
	n_count = ft_puthex(n, c);
	return (n_count);
}

int	print_pointer(va_list args)
{
	unsigned long	n;
	int				n_count;

	n = va_arg(args, unsigned long);
	ft_putstr_fd("0x", 1);
	n_count = ft_putpointer(n);
	return (n_count + 2);
}
