/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanco- <vblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:11:48 by vblanco-          #+#    #+#             */
/*   Updated: 2025/11/14 19:41:56 by vblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest1;
	unsigned char	*src1;

	src1 = (unsigned char *)src;
	dest1 = (unsigned char *)dest;
	if (src < dest)
	{
		src1 = src1 + n - 1;
		dest1 = dest1 + n - 1;
		while (n--)
			*dest1-- = *src1--;
	}
	else if (src >= dest)
	{
		while (n--)
			*dest1++ = *src1++;
	}
	return (dest);
}
/* 
int	main()
{
	char *s1 = "burger";
	char *s2 = "King";

	printf("Before memmove(): %s \n", s1);
	ft_memmove(&s1, &s2, 4);
	printf("After memmove():  %s", s1);
	return 0;
} */