/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanco- <vblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 20:30:58 by vblanco-          #+#    #+#             */
/*   Updated: 2025/11/06 20:30:58 by vblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	slen;
	void	*ptr;

	if (count == 0 || size == 0)
		return (malloc(0));
	if (count > __SIZE_MAX__ / size)
		return (NULL);
	slen = count * size;
	ptr = malloc(slen);
	if (ptr == NULL)
		return (NULL);
	else
		ft_bzero(ptr, slen);
	return (ptr);
}
