/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arbiter <Arbiter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 17:42:27 by spzona            #+#    #+#             */
/*   Updated: 2021/12/25 22:07:00 by Arbiter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nelements(long int num)
{
	int	c;

	c = 0;
	if (num == 0)
		c += 1;
	while (num > 0)
	{
		num = num / 10;
		c++;
	}
	return (c);
}

char	*ft_itoa(long int n)
{
	int			el;
	int			flag;
	char		*str;
	long int	num;

	flag = 0;
	num = n;
	if (num < 0)
	{
		flag = 1;
		num *= -1;
	}
	el = ft_nelements(num) + flag;
	str = (char *)malloc(el + 1 * sizeof(char));
	if (!str)
		return (NULL);
	if (flag > 0)
		str[0] = '-';
	str[el] = '\0';
	while (el-- > flag)
	{
		str[el] = ((num % 10) + '0');
		num = num / 10;
	}
	return (str);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s != NULL)
	{
		while (*s)
			write(fd, s++, 1);
	}
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_hex(unsigned int num, const char *type)
{
	char			*base;
	char			new_num;
	static int		c;

	base = "0123456789abcdef";
	c = 0;
	if (num >= 16)
		ft_hex(num / 16, type);
	if (*type == 'x')
		new_num = base[num % 16];
	else if (*type == 'X')
	{
		if ((base[num % 16] >= 'A' && base[num % 16] <= 'Z') || \
		(base[num % 16] >= 'a' && base[num % 16] <= 'z'))
			new_num = ((base[num % 16]) - 32);
		else
			new_num = base[num % 16];
	}
	write(1, &new_num, 1);
	c++;
	return (c);
}