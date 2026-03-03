/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanco- <vblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:23:33 by vblanco-          #+#    #+#             */
/*   Updated: 2025/11/14 19:39:54 by vblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*dest;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (f == NULL)
		return ((char *)s);
	dest = malloc(ft_strlen(s) + 1);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		dest[i] = f(i, s[i]);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/* int main(void)
{
	char *s1 = "burger king";
	char *dest;

	dest = ft_strmapi(s1, &toupper_w);
	printf("%s", dest);
	free (dest);
	return 0;	
} */