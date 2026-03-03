/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardcodes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanco- <vblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 18:13:34 by vblanco-          #+#    #+#             */
/*   Updated: 2026/03/03 19:32:41 by vblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Push_swap/push_swap.h"

//Sorter for 4 and 5 numbers list
void	ft_fivast(t_sta *tab)
{
	int	i_min;
	int	nb_diff;

	if (tab -> lena == 5)
		nb_diff = 2;
	else
		nb_diff = 1;
	while (tab -> lenb != nb_diff)
	{
		i_min = get_min_index(tab -> stack_a);
		if (i_min == 0)
			pb(tab, &tab -> stack_a, &tab -> stack_b);
		else if (i_min < tab->lena / 2)
			ra(tab, &tab -> stack_a);
		else
			rra(tab, &tab -> stack_a);
	}
	ft_threefast(tab);
	while (nb_diff-- > 0)
		pa(tab, &tab -> stack_b, &tab -> stack_a);
}

//Sorter for 3 numbers list
void	ft_threefast(t_sta *tab)
{
	int	a;
	int	b;

	a = get_max_index(tab -> stack_a);
	b = get_min_index(tab -> stack_a);
	if (a == 0 && b == 1)
		ra(tab, &tab -> stack_a);
	else if (a == 0 && b == 2)
	{
		sa(tab, &tab -> stack_a);
		rra(tab, &tab -> stack_a);
	}
	else if (a == 1 && b == 2)
		rra(tab, &tab -> stack_a);
	else if (a == 2 && b == 1)
		sa(tab, &tab -> stack_a);
	else if (a == 1 && b == 0)
	{
		rra(tab, &tab -> stack_a);
		sa(tab, &tab -> stack_a);
	}
}
