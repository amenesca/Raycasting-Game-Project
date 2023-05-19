/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 14:58:20 by amenesca          #+#    #+#             */
/*   Updated: 2022/05/21 13:29:14 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	char		*str;

	str = (char *) s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (char) c)
			return (str + i);
		i++;
	}
	return (NULL);
}
