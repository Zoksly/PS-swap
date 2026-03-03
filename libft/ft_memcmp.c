/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanco- <vblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:47:53 by vblanco-          #+#    #+#             */
/*   Updated: 2025/11/14 19:42:04 by vblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s0;
	unsigned char	*s;
	size_t			i;

	i = 0;
	s = (unsigned char *)s1;
	s0 = (unsigned char *)s2;
	while (i < n)
	{
		if (*s == *s0)
		{
			s++;
			s0++;
		}
		else
			return (*s - *s0);
		i++;
	}
	return (0);
}

/* int main(void)
{
	char *s1 = "Burger";
	char *s2 = "Burger";

	printf("%d", ft_memcmp(s1, s2, 6));
	return 0;
} */