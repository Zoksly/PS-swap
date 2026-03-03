/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanco- <vblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 18:14:04 by vblanco-          #+#    #+#             */
/*   Updated: 2026/03/03 18:14:07 by vblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

static size_t	printadress(int fd, const unsigned long n)
{
	if (n / 16)
		return (printadress(fd, n / 16) + printadress(fd, n % 16));
	else if (!(n / 10))
		ft_putchar(fd, n + '0');
	else
		ft_putchar(fd, (char) n - 10 + 'a');
	return (1);
}

size_t	ft_putadress(int fd, void *adress)
{
	if (!adress)
		return (ft_putstr(fd, "(nil)"));
	ft_putstr(fd, "0x");
	return (2 + printadress(fd, (unsigned long) adress));
}
