/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanco- <vblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 18:58:33 by vblanco-          #+#    #+#             */
/*   Updated: 2026/03/03 23:14:37 by vblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Choice of algo based on disorder / len_a + show benchm or not
void	ft_choose_algo(t_sta *tab)
{
	if ((int)tab -> lena == 3 && tab -> disorder != 0)
		ft_threefast(tab);
	else if ((tab -> lena == 5 || tab -> lena == 4) && tab -> disorder != 0)
		ft_fivast(tab);
	else if ((int)tab -> lena == 2 && tab -> disorder != 0)
		sa(tab, &tab -> stack_a);
	else if (((float)tab -> disorder < 0.2 && (float)tab -> disorder > 0)
		|| tab -> mode == 1)
		ft_simple(tab);
	else if (((float)tab -> disorder >= 0.2 && (float)tab -> disorder < 0.5)
		|| (tab -> mode == 2))
		ft_medium(tab, tab -> lena);
	else if (((float)tab -> disorder >= 0.5) || (tab -> mode == 3))
		radix_sort(tab);
	if (tab -> benchm == 1)
		get_benchmark(tab);
}

//Benchmark dashboard show up
void	get_benchmark(t_sta *tab)
{
	float	disorder;

	disorder = tab -> disorder * 100;
	if (tab -> mode == 1)
		ft_putstr_fd("Strategy used : Simple / (O(n2))\n", 2);
	else if (tab -> mode == 2)
		ft_putstr_fd("Strategy used : Medium / (O(n√n))\n", 2);
	else if (tab -> mode == 3)
		ft_putstr_fd("Strategy used : Complex / (O(n log n))\n", 2);
	else if (tab -> mode == 0)
		ft_putstr_fd("Strategy used : Adaptive\n", 2);
	ft_dprintf(2, "Disorder : %d%%\n", (int)(disorder));
	ft_dprintf(2, "Total operations : %d\n", tab -> ops.total);
	ft_dprintf(2, "sa : %d | sb : %d | ss: %d | pa : %d | pb : %d\n",
		tab -> ops.sa, tab -> ops.sb, tab -> ops.ss,
		tab -> ops.pa, tab -> ops.pb);
	ft_dprintf(2,
		"ra : %d | rb : %d | rr: %d | rra : %d | rrb : %d | rrr : %d\n",
		tab -> ops.ra, tab -> ops.rb, tab -> ops.rr,
		tab -> ops.rra, tab -> ops.rrb, tab -> ops.rrr);
	ft_dprintf(2, "il y a %d nombres\n", tab -> lena);
	if (is_sorted_stack(tab -> stack_a) == 1)
		write(2, "Trié gg frro\n", 14);
	else
		write(2, "caca fort\n", 11);
}
