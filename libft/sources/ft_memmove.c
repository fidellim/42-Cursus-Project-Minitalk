/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flim <flim@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:54:20 by flim              #+#    #+#             */
/*   Updated: 2022/02/28 17:21:36 by flim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	if (!dst && !src)
		return (0);
	if (dst > src)
	{
		while (len--)
			d[len] = s[len];
		return (dst);
	}
	while (len--)
		*d++ = *s++;
	return (dst);
}
