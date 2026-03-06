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

void	adaptative_mode(t_sta *tab)
{
	if (tab -> lena >= 2 && tab -> lena <= 5)
		small_sorters(tab);
	else if (((float)tab -> disorder >= 0.5))
		radix_sort(tab);
	else if (((float)tab -> disorder >= 0.2 && (float)tab -> disorder < 0.5))
		ft_medium(tab, tab -> lena);
	else if (((float)tab -> disorder < 0.2 && (float)tab -> disorder > 0))
		ft_simple(tab);
}

//Choice of algo based on disorder / len_a + show benchm or not
void	ft_choose_algo(t_sta *tab)
{
	if (tab -> mode == ADAPTIVE)
		adaptative_mode(tab);
	else if (tab -> mode == SIMPLE)
		ft_turksort(tab);
	else if (tab -> mode == MEDIUM)
		ft_medium(tab, tab -> lena);
	else if (tab -> mode == COMPLEX)
		radix_sort(tab);
	if (tab -> benchm == 1)
		get_benchmark(tab);
}

static void	print_benchm(t_sta *tab)
{
	ft_dprintf(2, "[bench] Total operations : %d\n", tab -> ops.total);
	ft_dprintf(2, ("[bench]"));
	ft_dprintf(2, "sa : %d | sb : %d | ss: %d | pa : %d | pb : %d\n",
		tab -> ops.sa, tab -> ops.sb, tab -> ops.ss,
		tab -> ops.pa, tab -> ops.pb);
	ft_dprintf(2, ("[bench]"));
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

//Benchmark dashboard show up
void	get_benchmark(t_sta *tab)
{
	float	disorder;

	disorder = tab -> disorder * 100;
	ft_dprintf(2, "[bench] Disorder : %d%%\n", (int)(disorder));
	if (tab -> mode == 1)
		ft_putstr_fd("[bench] Strategy used : Simple / (O(n2))\n", 2);
	else if (tab -> mode == 2)
		ft_putstr_fd("[bench] Strategy used : Medium / (O(n√n))\n", 2);
	else if (tab -> mode == 3)
		ft_putstr_fd("[bench] Strategy used : Complex / (O(n log n))\n", 2);
	else if (tab -> mode == 0)
		ft_putstr_fd("[bench] Strategy used : Adaptive\n", 2);
	print_benchm(tab);
}