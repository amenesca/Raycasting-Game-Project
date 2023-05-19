/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:42:58 by amenesca          #+#    #+#             */
/*   Updated: 2022/05/21 15:13:05 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	j = ft_strlen(src) + 1;
	i = dstsize - 1;
	if (j < dstsize)
		ft_memcpy(dst, src, j);
	else if (dstsize > 0)
		ft_memcpy(dst, src, i);
	dst[i] = '\0';
	return (j - 1);
}
