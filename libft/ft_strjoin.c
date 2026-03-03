/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanco- <vblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 20:33:51 by vblanco-          #+#    #+#             */
/*   Updated: 2025/11/06 20:33:51 by vblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	slen1;
	size_t	slen2;
	char	*str;

	if (s1 == NULL && s2 == NULL)
		return (ft_strdup(""));
	else if (s1 == NULL)
		return (ft_strdup(s2));
	else if (s2 == NULL)
		return (ft_strdup(s1));
	slen1 = ft_strlen(s1);
	slen2 = ft_strlen(s2);
	i = slen1 + slen2;
	str = malloc(i + 1);
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, s1, slen1);
	ft_memcpy(str + slen1, s2, slen2);
	str[i] = '\0';
	return (str);
}

/* int main(void)
{
    char *s1 = "Ma chaîne préfixe, ";
    char *s2 = "et ma chaîne suffixe !";
    char *joined_str;

    printf("s1: \"%s\"\n", s1);
    printf("s2: \"%s\"\n", s2);

    joined_str = ft_strjoin(s1, s2);

    if (joined_str == NULL)
    {
        printf("ÉCHEC : ft_strjoin a retourné NULL.\n");
        return (1);
    }

    printf("Résultat : \"%s\"\n", joined_str);

    // N'oublie JAMAIS de libérer ce que tu as alloué !
    free(joined_str);
    return (0);
} */