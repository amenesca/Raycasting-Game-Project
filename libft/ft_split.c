/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 11:38:48 by amenesca          #+#    #+#             */
/*   Updated: 2022/05/31 15:13:06 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	how_many_words(char const *s, char c);
static void		do_split(char **split, char const *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**ret;

	if (!s)
		return (NULL);
	ret = (char **) ft_calloc((how_many_words(s, c) + 1), sizeof(char *));
	if (!ret)
		return (NULL);
	do_split(ret, s, c);
	return (ret);
}

static size_t	how_many_words(char const *s, char c)
{
	size_t	j;
	size_t	i;

	j = 0;
	i = 0;
	while (*s != '\0')
	{
		if ((*s != c) && (i == 0))
		{
			i = 1;
			j++;
		}
		if (*s == c)
			i = 0;
		s++;
	}
	return (j);
}

static	void	do_split(char **str, char const *s, char c)
{
	size_t	len;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	len = 0;
	while (i < how_many_words(s, c))
	{
		while (s[j] == c && s[j] != '\0')
			j++;
		while (s[j + len] != c && s[j + len] != '\0')
		{
			len++;
		}
		str[i] = ft_substr(s, j, len);
		j = j + len;
		len = 0;
		i++;
	}
	str[i] = NULL;
}
