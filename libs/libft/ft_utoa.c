/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 18:38:05 by amenesca          #+#    #+#             */
/*   Updated: 2022/06/21 18:39:47 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_unsigned_len(unsigned int n)
{
	size_t	n_len;

	n_len = 1;
	while (n >= 10)
	{
		n /= 10;
		n_len++;
	}
	return (n_len);
}

char	*ft_utoa(unsigned int n)
{
	size_t	n_len;
	char	*str;

	n_len = ft_unsigned_len(n);
	str = malloc(n_len + 1);
	if (!str)
		return (NULL);
	str[n_len] = '\0';
	if (n == 0)
		str[0] = '0';
	str[n_len--] = '\0';
	while (n)
	{
		str[n_len--] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}
