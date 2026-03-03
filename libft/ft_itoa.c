/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanco- <vblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 23:52:35 by vblanco-          #+#    #+#             */
/*   Updated: 2025/11/21 21:59:21 by vblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_print_nb(int n, int i)
{
	char	*dest;

	if (n < 0)
	{
		dest = ft_calloc(i + 2, 1);
		dest[0] = '-';
		n = n * -1;
	}
	else
		dest = ft_calloc(i + 1, 1);
	if (dest == NULL)
		return (NULL);
	if (dest[0] == '-')
		i++;
	dest[i] = '\0';
	while (n > 0)
	{
		dest[--i] = (n % 10) + '0';
		n = n / 10;
	}
	return (dest);
}

char	*ft_itoa(int n)
{
	int		i;
	int		nb;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = 0;
	nb = n;
	if (nb < 0)
		nb *= -1;
	if (nb == 0)
		return (ft_strdup("0"));
	while (nb != 0)
	{
		nb = nb / 10;
		i++;
	}
	return (ft_print_nb(n, i));
}

/* int main(void)
{
	printf("%s\n", ft_itoa(-42));
} */