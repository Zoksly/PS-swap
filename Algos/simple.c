/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanco- <vblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 18:13:47 by vblanco-          #+#    #+#             */
/*   Updated: 2026/03/03 18:13:47 by vblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Push_swap/push_swap.h"

int	get_min_index(t_list *stack)
{
	t_list	*current;
	t_list	*min;
	int		i;
	int		imin;

	current = stack;
	min = stack;
	i = 0;
	imin = 0;
	while (current)
	{
		if ((long)current -> content < (long)min -> content)
		{
			min = current;
			imin = i;
		}
		current = current -> next;
		i++;
	}
	return (imin);
}

void	ft_simple(t_sta *tab)
{
	t_list	*stacka;
	t_list	*stackb;
	int		j;

	stacka = tab -> stack_a;
	stackb = tab -> stack_b;
	while (stacka)
	{
		j = get_min_index(stacka);
		if (j == 0)
			pb(tab, &stacka, &stackb);
		else if (j < (int)tab -> lena / 2)
			ra(tab, &stacka);
		else
			rra(tab, &stacka);
	}
	while (stackb)
		pa(tab, &stackb, &stacka);
	tab -> stack_a = stacka;
	tab -> stack_b = stackb;
}
