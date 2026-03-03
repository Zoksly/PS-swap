/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanco- <vblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 19:14:53 by vblanco-          #+#    #+#             */
/*   Updated: 2026/03/03 19:14:53 by vblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_sta *tab, t_list **stackb, t_list **stacka)
{
	t_list	*pushb;

	if (!(*stackb))
		return ;
	pushb = *stackb;
	*stackb = (*stackb)-> next;
	pushb -> next = *stacka;
	*stacka = pushb;
	tab -> lena++;
	tab -> lenb--;
	tab -> ops.pa += 1;
	tab -> ops.total += 1;
	write(1, "pa\n", 3);
}

void	pb(t_sta *tab, t_list **stacka, t_list **stackb)
{
	t_list	*pusha;

	if (!(*stacka))
		return ;
	pusha = *stacka;
	*stacka = (*stacka)-> next;
	pusha -> next = *stackb;
	*stackb = pusha;
	tab -> lena--;
	tab -> lenb++;
	tab -> ops.pb += 1;
	tab -> ops.total += 1;
	write(1, "pb\n", 3);
}
