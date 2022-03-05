/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flim <flim@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:32:10 by flim              #+#    #+#             */
/*   Updated: 2022/02/28 17:49:42 by flim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	n_len(int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static int	find_zero(int len)
{
	int	i;

	i = 1;
	if (len == 1)
		return (1);
	while (len > 1)
	{
		i *= 10;
		len--;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	int		len;
	int		len2;
	char	*result;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n > 2147483647 || n < -2147483648)
		return (NULL);
	i = 0;
	len = n_len(n);
	len2 = len;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	if (n < 0)
	{
		n *= -1;
		result[i++] = '-';
		len--;
	}
	while (i < len2)
		result[i++] = ((n / find_zero(len--)) % 10) + 48;
	result[i] = '\0';
	return (result);
}
