/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanco- <vblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 20:33:46 by vblanco-          #+#    #+#             */
/*   Updated: 2025/11/06 20:33:46 by vblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char		*dest;
	size_t		i;

	if (s1 == NULL)
		return (NULL);
	dest = malloc(ft_strlen(s1) + 1);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/* 
int main(void)
{
	int n = 123;
    char *s = "-";

    printf("%s", ft_strdup(s));
	s = "123";
	printf("%s", ft_strdup(s));
    return 0;
} */