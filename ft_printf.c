/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arbiter <Arbiter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 17:42:27 by spzona            #+#    #+#             */
/*   Updated: 2021/12/26 04:33:54 by Arbiter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_arg_checker(const char *ptr, va_list args)
{
	if (*ptr == 'd' || *ptr == 'i' || *ptr == 'u')
	{
		if (*ptr == 'u')
			return (ft_decimal(va_arg(args, unsigned int)));
		else
			return (ft_decimal(va_arg(args, int)));
	}
	else if (*ptr == 'c')
		return (ft_char(va_arg(args, int)));
	else if (*ptr == 's')
		return (ft_string(va_arg(args, char *)));
	else if (*ptr == 'x' || *ptr == 'X' || *ptr == 'p')
	{
		if (*ptr == 'x' || *ptr == 'X')
			return (ft_hex(va_arg(args, unsigned int), ptr));
		else
			return (ft_pointer(va_arg(args, unsigned long int)));
	}
	else if (*ptr == '%')
	{
		write (1, ptr, 1);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		c;
	int		num;

	c = -1;
	num = 0;
	va_start(ap, format);
	while (format[++c])
	{
		if (format[c] == '%')
		{
			c += 1;
			num += ft_arg_checker(&format[c], ap);
		}
		else
		{
			write (1, &format[c], 1);
			num++;
		}
	}
	va_end(ap);
	return (num);
}
