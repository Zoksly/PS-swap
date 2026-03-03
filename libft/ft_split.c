/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanco- <vblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:33:31 by vblanco-          #+#    #+#             */
/*   Updated: 2025/11/10 17:33:31 by vblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	count_words;

	count_words = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			count_words += 1;
			while (*s != c && *s != '\0')
				s++;
		}
		if (*s != '\0')
			s++;
	}
	return (count_words);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	slens;
	char	**tab;
	size_t	words;

	if (s == NULL)
		return (NULL);
	tab = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (tab == NULL)
		return ((char **) NULL);
	i = 0;
	slens = 0;
	words = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		slens = i;
		while (s[i] != '\0' && s[i] != c)
			i++;
		if (i - slens > 0)
			tab[words++] = ft_substr(s, slens, (i - slens));
	}
	tab[words] = NULL;
	return (tab);
}
