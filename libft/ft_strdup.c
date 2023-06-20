/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:32:05 by amenesca          #+#    #+#             */
/*   Updated: 2022/06/01 12:44:20 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*s;

	s = (char *) ft_calloc((ft_strlen(s1) + 1), sizeof(char));
	if (!s)
		return (NULL);
	i = 0;
	while (i <= ft_strlen(s1))
	{
		s[i] = s1[i];
		i++;
	}
	return ((char *)(s));
}
