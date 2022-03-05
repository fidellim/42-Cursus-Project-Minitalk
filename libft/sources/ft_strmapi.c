/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flim <flim@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:33:54 by flim              #+#    #+#             */
/*   Updated: 2022/02/28 17:50:08 by flim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		n;
	char	*ptr;

	if (!s || !f)
		return (NULL);
	n = 0;
	ptr = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!ptr)
		return (NULL);
	while (s[n])
	{
		ptr[n] = (f)(n, s[n]);
		n++;
	}
	ptr[n] = '\0';
	return (ptr);
}
