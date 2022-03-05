/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_string_funcs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flim <flim@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 23:14:34 by flim              #+#    #+#             */
/*   Updated: 2022/02/27 11:56:05 by flim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_char(va_list args)
{
	ft_putchar_fd(va_arg(args, int), 1);
	return (1);
}

int	print_str(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}
