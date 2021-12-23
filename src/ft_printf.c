/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spzona <spzona@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 17:42:27 by spzona            #+#    #+#             */
/*   Updated: 2021/12/23 18:16:36 by spzona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putchar(char c)
{
	int	i;

	i = write(1, &c, 1);
	return (i);
}

int	ft_arg_checker(char c, va_list ap)
{
	int	res;

	res = 0;
	if (c == 'c')
		res += putchar(va_arg(ap, int)); 
}