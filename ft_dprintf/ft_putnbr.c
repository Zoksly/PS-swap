/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 18:10:03 by tchevrie          #+#    #+#             */
/*   Updated: 2022/10/05 05:35:24 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

static size_t	print_nb(int fd, long nb)
{
	if (nb / 10)
		return (print_nb(fd, nb / 10) + print_nb(fd, nb % 10));
	else
		return (ft_putchar(fd, nb + '0'));
}

size_t	ft_putnbr(int fd, const int n)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		nb = -nb;
		return (ft_putchar(fd, '-') + print_nb(fd, nb));
	}
	else
		return (print_nb(fd, nb));
}
