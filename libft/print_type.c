/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:38:39 by amenesca          #+#    #+#             */
/*   Updated: 2022/06/22 13:35:44 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_type(va_list argptr, char type)
{
	int		len;

	len = 0;
	if (type == 'c')
		len += ft_putchar(va_arg(argptr, int));
	else if (type == 's')
		len += ft_putstr(va_arg(argptr, char *));
	else if (type == 'i' || type == 'd')
		len += ft_itoa_count(va_arg(argptr, int));
	else if (type == 'p')
		len += ft_check_ptr(va_arg(argptr, unsigned long), type);
	else if (type == 'x' || type == 'X')
		len += ft_check_hexa(va_arg(argptr, int), type);
	else if (type == 'u')
		len += ft_nbr_u(va_arg(argptr, unsigned int));
	else if (type == '%')
		len += write(1, "%", 1);
	return (len);
}
