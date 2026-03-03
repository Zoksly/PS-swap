/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanco- <vblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 21:25:23 by vblanco-          #+#    #+#             */
/*   Updated: 2025/11/19 18:07:40 by vblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*temps;
	size_t	alloc;
	size_t	slen;

	if (s == NULL)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	if (slen - start < len)
		alloc = slen - start;
	else
		alloc = len;
	temps = malloc(alloc + 1);
	if (temps == NULL)
		return (NULL);
	i = 0;
	while (s[start] != '\0' && i < len)
		temps[i++] = s[start++];
	temps[i] = '\0';
	return (temps);
}

/* int main(void)
{
	char *s1 = "Burger king";
	
	printf("%s", ft_substr(s1, 6, 5));
	return 0;
} */