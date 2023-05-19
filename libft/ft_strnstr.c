/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 11:43:34 by amenesca          #+#    #+#             */
/*   Updated: 2022/05/19 16:05:19 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[0] == '\0' || needle == NULL)
		return ((char *) haystack);
	while (i <= len && haystack[i] != '\0')
	{
		j = 0;
		while (haystack[i + j] == needle[j] && i + j < len)
		{
			if (needle[j + 1] == '\0')
				return ((char *) haystack + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
/*#include <stdio.h>
#include <string.h>

int main(void)
{
	const char *haystack = "nhoque é mac macarrão de batata";
	const char *needle = "mac";

	printf("%s\n", ft_strnstr(haystack, needle, 26));
	printf("%s\n", strnstr(haystack, needle, 26));
}*/
