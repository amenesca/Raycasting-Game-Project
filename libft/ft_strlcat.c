/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 10:24:20 by amenesca          #+#    #+#             */
/*   Updated: 2022/05/16 09:40:18 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_dst;
	size_t	i;
	size_t	ret;

	len_dst = ft_strlen(dst);
	i = 0;
	if (dstsize > len_dst)
		ret = len_dst + ft_strlen(src);
	else
		ret = dstsize + ft_strlen(src);
	while (src[i] != '\0' && (len_dst) + 1 < dstsize)
	{
		dst[len_dst] = src[i];
		len_dst++;
		i++;
	}
	dst[len_dst] = '\0';
	return (ret);
}
