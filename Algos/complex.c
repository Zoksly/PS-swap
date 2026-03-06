/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanco- <vblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 18:13:28 by vblanco-          #+#    #+#             */
/*   Updated: 2026/03/03 19:29:34 by vblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Push_swap/push_swap.h"

int	get_max_bits(int lena, int *array)
{
	int	value;
	int	i_bits;

	value = array[lena - 1];
	i_bits = 0;
	while (value > 0)
	{
		value = value >> 1;
		i_bits++;
	}
	return (i_bits);
}

int	count_bits(t_sta *tab, int i_bits, int *array, int nb_node)
{
	int	index;
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = nb_node;
	while (k != 0)
	{
		index = get_index(tab -> stack_a, array, nb_node);
		if (((index >> i_bits) & 1) == 1)
			i++;
		else
			j++;
		k--;
	}
	if (i > j)
		return (1);
	return (0);
}

void	check_bits(t_sta *tab, int i_bits, int *array, int nb_node)
{
	int	index;
	int	i_ops;

	i_ops = 0;
	while (i_ops < nb_node)
	{
		index = get_index(tab -> stack_a, array, nb_node);
		if (((index >> i_bits) & 1) == 1)
			ra(tab, &tab -> stack_a);
		else if (((index >> i_bits) & 1) == 0)
			pb(tab, &tab -> stack_a, &tab -> stack_b);
		i_ops++;
	}
	while (tab -> lenb != 0)
		pa(tab, &tab -> stack_b, &tab -> stack_a);
}

void	radix_sort(t_sta *tab)
{
	int	*array;
	int	i_bits;
	int	max_bits;

	array = stack_to_array(tab -> stack_a, tab -> lena, 1);
	if (!array)
		return ;
	i_bits = 0;
	max_bits = get_max_bits(tab -> lena, array);
	while (i_bits < max_bits)
	{
		check_bits(tab, i_bits, array, tab -> lena);
		i_bits++;
	}
	free(array);
}
