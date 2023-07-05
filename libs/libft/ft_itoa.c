/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 08:57:29 by amenesca          #+#    #+#             */
/*   Updated: 2022/05/26 15:56:02 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	nbsize(int n)
{
	size_t	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{	
	char	*str;
	int		i;
	long	x;

	x = n;
	i = nbsize(n);
	str = malloc(i + 1);
	if (str == NULL)
		return (NULL);
	if (x < 0)
	{
		str[0] = '-';
		x = -x;
	}
	if (x == 0)
		str[0] = '0';
	str[i--] = '\0';
	while (x)
	{
		str[i] = x % 10 + '0';
		i--;
		x = x / 10;
	}
	return (str);
}
