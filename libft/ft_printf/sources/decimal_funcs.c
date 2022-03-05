/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flim <flim@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 12:06:15 by flim              #+#    #+#             */
/*   Updated: 2022/02/28 18:35:50 by flim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_putnbr(int n)
{
	int	n_count;

	n_count = 1;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		n_count++;
		n = -n;
	}
	if (n > 9)
		n_count += ft_putnbr(n / 10);
	ft_putchar_fd(n % 10 + '0', 1);
	return (n_count);
}

static int	ft_putunbr(unsigned int n)
{
	int	n_count;

	n_count = 1;
	if (n > 9)
		n_count += ft_putunbr(n / 10);
	ft_putchar_fd(n % 10 + '0', 1);
	return (n_count);
}

int	print_int(va_list args)
{
	int	n;
	int	n_count;

	n = va_arg(args, int);
	n_count = ft_putnbr(n);
	return (n_count);
}

int	print_uint(va_list args)
{
	unsigned int	n;
	int				n_count;

	n = va_arg(args, unsigned int);
	n_count = ft_putunbr(n);
	return (n_count);
}
