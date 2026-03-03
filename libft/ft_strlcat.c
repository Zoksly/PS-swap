/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanco- <vblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:30:37 by vblanco-          #+#    #+#             */
/*   Updated: 2025/11/21 22:00:51 by vblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

size_t	ft_strlcat(char *dest, const char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	dlen;
	unsigned int	slen;

	i = 0;
	j = 0;
	if (src == NULL)
		return (0);
	dlen = ft_strlen(dest);
	slen = ft_strlen(src);
	if (size <= dlen)
		return (size + slen);
	while (dest[j] != '\0')
		j++;
	while (dlen + i < size - 1 && src[i])
		dest[j++] = src[i++];
	dest[j] = '\0';
	return (dlen + slen);
}

/* int	main(void)
{
	char s1[50] = "miam";
	char *s2 = "burger king";

	ft_strlcat(s1, s2, 15);
	printf("%s", s1);
	return 0;
} */
