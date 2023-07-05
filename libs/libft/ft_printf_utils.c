/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 18:34:23 by amenesca          #+#    #+#             */
/*   Updated: 2022/06/21 18:35:51 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	len;

	if (!str)
	{
		return (write(1, "(null)", 6));
	}
	len = ft_strlen(str);
	return (write(1, str, len));
}

int	ft_nbr_u(unsigned int number)
{
	char	*str;
	int		len;

	len = 0;
	str = ft_utoa(number);
	len += ft_putstr(str);
	free(str);
	return (len);
}

int	ft_itoa_count(int n)
{
	char	*str;
	int		len;

	len = 0;
	str = ft_itoa(n);
	len += ft_putstr(str);
	free(str);
	return (len);
}
