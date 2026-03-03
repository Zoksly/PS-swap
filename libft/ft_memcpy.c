/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanco- <vblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:06:38 by vblanco-          #+#    #+#             */
/*   Updated: 2025/11/14 19:42:01 by vblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*str;
	const unsigned char	*in;

	in = (const unsigned char *) src;
	str = (unsigned char *) dest;
	while (n > 0)
	{
		*str++ = (unsigned char)*in;
		in++;
		n--;
	}
	return (dest);
}

/* int main(void)
{
    // Initialize a variable
    int a = 2054781;
    int b = 10;
    
    printf("Value of b before calling memcpy: %d\n", b);

    // Use memcpy to copy the value of 'a' into 'b'
    ft_memcpy(&b, &a, sizeof(int));

    printf("Value of b after calling memcpy: %d\n", b);

    return 0;
} */