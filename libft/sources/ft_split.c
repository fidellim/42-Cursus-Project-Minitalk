/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flim <flim@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:55:29 by flim              #+#    #+#             */
/*   Updated: 2022/02/28 17:22:09 by flim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_delimeter(char c, char target)
{
	if (c == target)
		return (1);
	return (0);
}

static	char	*my_strdup(char *s, char target)
{
	char	*new_word;
	int		i;

	i = 0;
	while (s[i] && !ft_is_delimeter(s[i], target))
		i++;
	new_word = malloc(sizeof(char) * (i + 1));
	if (!new_word)
		return (NULL);
	i = 0;
	while (s[i] && !ft_is_delimeter(s[i], target))
	{
		new_word[i] = s[i];
		i++;
	}
	new_word[i] = '\0';
	return (new_word);
}

static int	ft_total_words(char *s, char target)
{
	int	total_words;

	total_words = 0;
	while (*s)
	{
		while (*s && ft_is_delimeter(*s, target))
			s++;
		if (*s && !ft_is_delimeter(*s, target))
		{
			while (*s && !ft_is_delimeter(*s, target))
				s++;
			total_words++;
		}
	}
	return (total_words);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**arr_of_s;

	if (!s)
		return (NULL);
	i = 0;
	arr_of_s = malloc(sizeof(char *) * (ft_total_words((char *)s, c) + 1));
	if (!arr_of_s)
		return (NULL);
	while (*s)
	{
		while (*s && ft_is_delimeter(*s, c))
			s++;
		if (*s && !ft_is_delimeter(*s, c))
		{
			arr_of_s[i] = my_strdup((char *)s, c);
			i++;
			while (*s && !ft_is_delimeter(*s, c))
				s++;
		}
	}
	arr_of_s[i] = 0;
	return (arr_of_s);
}
