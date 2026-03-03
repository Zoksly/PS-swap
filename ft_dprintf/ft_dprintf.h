/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanco- <vblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 18:13:56 by vblanco-          #+#    #+#             */
/*   Updated: 2026/03/03 18:19:03 by vblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DPRINTF_H
# define FT_DPRINTF_H

# include "../Push_swap/push_swap.h"
# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_dprintf(int fd, const char *str, ...);

size_t	ft_putadress(int fd, void *adress);
size_t	ft_putchar(int fd, const char c);
size_t	ft_puthexa_lower(int fd, const unsigned int n);
size_t	ft_puthexa_upper(int fd, const unsigned int n);
size_t	ft_putnbr(int fd, const int n);
size_t	ft_putstr(int fd, const char *str);
size_t	ft_putunbr(int fd, const unsigned int n);
size_t	ft_strlen(const char *s);

#endif