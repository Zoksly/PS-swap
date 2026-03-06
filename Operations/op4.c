/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op4.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanco- <vblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 19:12:47 by vblanco-          #+#    #+#             */
/*   Updated: 2026/03/03 19:12:47 by vblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rr(t_list **stack1)
{
	t_list	*temp;
	t_list	*last;

	if (!(stack1) || !(*stack1) || !((*stack1)->next))
		return ;
	temp = *stack1;
	while ((temp -> next -> next))
		temp = temp -> next;
	last = temp -> next;
	temp -> next = NULL;
	last -> next = *stack1;
	*stack1 = last;
}

void	rra(t_sta *tab, t_list **stacka)
{
	ft_rr(stacka);
	tab -> ops.rra += 1;
	tab -> ops.total += 1;
	write(1, "rra\n", 4);
}

void	rrb(t_sta *tab, t_list **stackb)
{
	ft_rr(stackb);
	tab -> ops.rrb += 1;
	tab -> ops.total += 1;
	write(1, "rrb\n", 4);
}

void	rrr(t_sta *tab, t_list **stacka, t_list **stackb)
{
	ft_rr(stacka);
	ft_rr(stackb);
	tab -> ops.rrr += 1;
	tab -> ops.total += 1;
	write(1, "rrr\n", 4);
}
