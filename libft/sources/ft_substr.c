/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flim <flim@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:32:02 by flim              #+#    #+#             */
/*   Updated: 2022/02/28 17:49:55 by flim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ptr;
	unsigned int	len_s;

	if (!s)
		return (0);
	len_s = (unsigned int)ft_strlen(s);
	if (len > len_s)
		len = len_s - start;
	if (start >= len_s)
		return (ft_strdup(""));
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (0);
	ft_memcpy(ptr, s + start, len);
	ptr[len] = '\0';
	return (ptr);
}
