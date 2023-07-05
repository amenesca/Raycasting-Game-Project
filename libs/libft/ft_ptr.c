/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 18:36:18 by amenesca          #+#    #+#             */
/*   Updated: 2022/06/22 10:35:41 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr_len(unsigned long dec)
{
	int	len;

	len = 0;
	while (dec != 0)
	{
		len++;
		dec = dec / 16;
	}
	return (len);
}

void	ft_hexa_ptr(unsigned long dec, char type)
{
	char	*base;

	base = "0123456789abcdef";
	if (dec >= 16)
	{
		ft_hexa_ptr(dec / 16, type);
		ft_hexa_ptr(dec % 16, type);
	}
	else
	{
		ft_putchar(base[dec]);
	}
}

int	ft_check_ptr(unsigned long n, char type)
{
	int	len;

	len = 0;
	if (!n)
		return (write(1, "0x0", 3));
	len += write(1, "0x", 2);
	if (n)
	{
		ft_hexa_ptr(n, type);
		len += ft_ptr_len(n);
	}
	return (len);
}
