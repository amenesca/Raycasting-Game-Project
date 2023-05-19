/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 08:20:41 by amenesca          #+#    #+#             */
/*   Updated: 2022/06/01 12:45:04 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*temp;
	char	*str;
	size_t	i;
	size_t	len;

	len = ft_strlen(s);
	str = (char *) s;
	i = 0;
	temp = NULL;
	if (c == '\0')
		return ((char *) s + len);
	while (i < ft_strlen(str))
	{
		if (str[i] == (char) c)
			temp = str + i;
		i++;
		if (str[i] == (char) c)
			temp = str + i;
	}
	return (temp);
}
