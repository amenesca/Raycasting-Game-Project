/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:15:55 by amenesca          #+#    #+#             */
/*   Updated: 2022/05/18 14:51:59 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = (char *) dst;
	s = (const char *) src;
	if (s == d || n == 0)
		return (dst);
	while (n--)
	{
		*d++ = *s++;
	}
	return (dst);
}
