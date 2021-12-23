/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spzona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:07:46 by spzona            #+#    #+#             */
/*   Updated: 2021/10/07 15:07:53 by spzona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*dup;
	size_t	i;

	i = 0;
	dup = (char *)s;
	while (i < n)
	{
		dup[i] = 0;
		i++;
	}
}