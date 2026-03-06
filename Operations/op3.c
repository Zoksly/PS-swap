/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op3.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanco- <vblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 19:13:51 by vblanco-          #+#    #+#             */
/*   Updated: 2026/03/03 19:13:51 by vblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_r(t_list **stack1)
{
	t_list	*first;
	t_list	*last;

	if (!(stack1) || !((*stack1)->next))
		return ;
	first = *stack1;
	last = ft_lstlast(*stack1);
	*stack1 = first -> next;
	last -> next = first;
	first -> next = NULL;
}

void	ra(t_sta *tab, t_list **stacka)
{
	ft_r(stacka);
	tab -> ops.ra += 1;
	tab -> ops.total += 1;
	write(1, "ra\n", 3);
}

void	rb(t_sta *tab, t_list **stackb)
{
	ft_r(stackb);
	tab -> ops.rb += 1;
	tab -> ops.total += 1;
	write(1, "rb\n", 3);
}

void	rr(t_sta *tab, t_list **stacka, t_list **stackb)
{
	ft_r(stacka);
	ft_r(stackb);
	tab -> ops.rr += 1;
	tab -> ops.total += 1;
	write(1, "rr\n", 3);
}
