/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flim <flim@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:58:28 by flim              #+#    #+#             */
/*   Updated: 2022/02/28 17:49:15 by flim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*cpy;

	len = ft_strlen(s1);
	cpy = (char *)malloc((len + 1) * sizeof(char));
	if (!cpy)
		return (NULL);
	while (*s1)
	{
		*cpy = *s1;
		cpy++;
		s1++;
	}
	*cpy = *s1;
	return (cpy - len);
}
