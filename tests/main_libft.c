/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flim <flim@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:55:01 by flim              #+#    #+#             */
/*   Updated: 2022/03/07 15:25:22 by flim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"

// Check if libft is usable
int	main(void)
{
	ft_printf("THIS IS LIBFT HEADER\n");
	ft_printf("len of this: %d\n", ft_strlen("hi"));
	ft_printf("Char or not: %d\n", ft_isalpha('9'));
	return (0);
}
