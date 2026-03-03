/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanco- <vblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 18:13:53 by vblanco-          #+#    #+#             */
/*   Updated: 2026/03/03 19:39:40 by vblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int	ft_conversions(int fd, char c, va_list ap)
{
	if (c == 'c')
		return (ft_putchar(fd, c));
	else if (c == 's')
		return (ft_putstr(fd, va_arg(ap, char *)));
	else if (c == 'p')
		return (ft_putadress(fd, va_arg(ap, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(fd, va_arg(ap, int)));
	else if (c == 'u')
		return (ft_putunbr(fd, va_arg(ap, unsigned int)));
	else if (c == 'x')
		return (ft_puthexa_lower(fd, va_arg(ap, unsigned int)));
	else if (c == 'X')
		return (ft_puthexa_upper(fd, va_arg(ap, unsigned int)));
	else if (c == '%')
		return (ft_putchar(fd, c));
	else
		return (0);
}

int	ft_dprintf(int fd, const char *str, ...)
{
	int		tmp;
	int		len;
	int		i;
	va_list	ap;

	if (fd < 0 || !str)
		return (-1);
	tmp = 0;
	len = 0;
	i = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			tmp = ft_conversions(fd, str[i + 1], ap);
			i++;
		}
		else
			tmp = ft_putchar(fd, str[i]);
		len += tmp;
		i++;
	}
	va_end(ap);
	return (len);
}
