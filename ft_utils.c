/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arbiter <Arbiter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 17:42:29 by spzona            #+#    #+#             */
/*   Updated: 2021/12/25 22:04:30 by Arbiter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_decimal(unsigned long int num)
{
	char	*res;
	int		counter;

	res = ft_itoa(num);
	ft_putstr_fd(res, 1);
	counter = ft_strlen(res);
	free(res);
	return (counter);
}

size_t	ft_string(const char *c)
{
	size_t	a;
	size_t	b;

	if (!c)
		return (ft_string("(null)"));
	a = 0;
	b = ft_strlen(c);
	while (a < b)
	{
		write (1, c++, 1);
		a++;
	}
	return (a);
}

size_t	ft_char(const int c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_pointer(unsigned long int num)
{
	char			*base;
	char			new_num;
	static int		c;

	base = "0123456789abcdef";
	c = 0;
	if (num >= 16)
		ft_pointer(num / 16);
	if (!c)
	{
		write (1, "0x", 2);
		c += 2;
	}
	new_num = base[num % 16];
	write(1, &new_num, 1);
	c++;
	return (c);
}

