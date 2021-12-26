/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arbiter <Arbiter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 17:42:33 by spzona            #+#    #+#             */
/*   Updated: 2021/12/26 04:26:02 by Arbiter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

char	*ft_itoa(long int n);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
int		ft_decimal(unsigned long int num);
size_t	ft_string(const char *c);
size_t	ft_char(const int c);
int		ft_hex(unsigned int num, const char *type);
int		ft_pointer(unsigned long int num);
int		ft_printf(const char *format, ...);

#endif