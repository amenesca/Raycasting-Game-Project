/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:13:38 by amenesca          #+#    #+#             */
/*   Updated: 2022/05/21 15:10:26 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(int a);

int	ft_atoi(const char *str)
{
	long	res;
	long	sign;
	long	x;

	res = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		x = res;
		res = (res * 10) + (*str - '0');
		if (res < x)
			return (check(sign));
		str++;
	}
	return (res * sign);
}

static int	check(int sign)
{
	if (sign < 0)
		return (0);
	else
		return (-1);
}
