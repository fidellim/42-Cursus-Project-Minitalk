/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flim <flim@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:57:54 by flim              #+#    #+#             */
/*   Updated: 2022/02/28 17:23:37 by flim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	needle_len;

	i = 0;
	needle_len = ft_strlen(needle);
	if (!needle_len)
		return ((char *)haystack);
	while (i < len && haystack[i])
	{
		j = 0;
		while (i + j < len && haystack[i + j]
			&& haystack[i + j] == needle[j])
			j++;
		if (j == needle_len)
			return ((char *)&haystack[i]);
		i++;
	}
	return (0);
}
