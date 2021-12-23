/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spzona <spzona@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 17:42:29 by spzona            #+#    #+#             */
/*   Updated: 2021/12/23 19:59:01 by spzona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_elements(long int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i += 1;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return(i);
}

size_t	ft_putstr_f(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return(ft_putstr_f("(null)"));
	while (s[i])
	{
		ft_putchar_f(s[i]);
		i++;
	}
	return (i);
}

size_t	ft_putchar_f(char *s)
{
	write(1, &s, 1);
	return(0);
}

size_t	ft_puthex(unsigned int n, char *t)
{
	char			*base;
	static int		i;
	char			new;

	base = "0123456789abcdef";
	i = 0;
	if (n >= 16)
		ft_puthex(n / 16, t);
	else if (*t == 'x')
		new = base[n % 16];
	else if (*t == 'X')
	{
		if ((base[n % 16] >= 'A' && base[n % 16] <= 'Z') || \ 
		(base[n % 16] >= 'a' && base[n % 16] <= 'z'))
			new = ((base[n % 16]) - 32);
		else	new = base[n % 16];
	}
	write(1, &new, 1);
	i++;
	return (i);
}

size_t	ft_putpointer(void *ptr, char *base)
{
}