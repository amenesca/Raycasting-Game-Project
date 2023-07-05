/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 18:32:55 by amenesca          #+#    #+#             */
/*   Updated: 2023/05/18 14:32:25 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

int		ft_printf(const char *str, ...);
int		ft_hexa_len(unsigned int dec);
void	ft_hexa(unsigned int dec, char type);
int		ft_check_hexa(unsigned int n, char type);
int		ft_ptr_len(unsigned long dec);
void	ft_hexa_ptr(unsigned long dec, char type);
int		ft_check_ptr(unsigned long n, char type);
char	*ft_utoa(unsigned int n);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_nbr_u(unsigned int number);
int		ft_itoa_count(int n);
int		print_type(va_list argptr, char type);
size_t	ft_unsigned_len(unsigned int n);

#endif
