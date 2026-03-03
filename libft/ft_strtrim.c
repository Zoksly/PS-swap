/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanco- <vblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 20:04:31 by vblanco-          #+#    #+#             */
/*   Updated: 2025/11/14 19:40:12 by vblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*dest;

	j = 0;
	if (s1 == NULL)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	if (s1[j] == '\0')
		return (ft_strdup(""));
	i = ft_strlen(s1) - 1;
	while (s1[j] != '\0' && ft_strchr(set, s1[j]) != NULL)
		j++;
	while (i > j && ft_strchr(set, s1[i]) != NULL)
		i--;
	dest = ft_substr(s1, j, (i - j) + 1);
	return (dest);
}

/* int main(void)
{
	char *s1 = " a bBurger Kingb a ";
	char *set = " ab";

	printf("%s", ft_strtrim(s1, set));
	return 0;
} */