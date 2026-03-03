/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanco- <vblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 00:26:55 by vblanco-          #+#    #+#             */
/*   Updated: 2025/11/14 19:42:11 by vblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i != n)
	{
		if (*(unsigned char *)s == (unsigned char)c)
			return ((char *)s);
		s++;
		i++;
	}
	return (NULL);
}

/* int main(void)
{
    char    test[10] = {1, 1, 1, 0, 4, 1, 1, 1};
	char	*dest = ft_memchr(test, 4, 7);
	if (dest == NULL)
	{
		printf("memchr returned NULL\n");
		return 1;
	}
    printf("memchr(\"%s\", '%d', %d) returned %s\n", test, 4, 7, dest);
} */

/* int main(void)
{
	char *s1 = "Burger King";
	
	printf("%s", ft_memchr(s1, 'K', 10));
	return 0;
} */