/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_lower.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanco- <vblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 18:14:21 by vblanco-          #+#    #+#             */
/*   Updated: 2026/03/03 18:14:23 by vblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

size_t	ft_puthexa_lower(int fd, const unsigned int n)
{
	if (n / 16)
		return (ft_puthexa_lower(fd, n / 16) + ft_puthexa_lower(fd, n % 16));
	else if (!(n / 10))
		ft_putchar(fd, n + '0');
	else
		ft_putchar(fd, (char) n - 10 + 'a');
	return (1);
}
