/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanco- <vblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 19:17:41 by vblanco-          #+#    #+#             */
/*   Updated: 2026/03/03 19:17:41 by vblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_s(t_list **stack)
{
	t_list	*temp;

	if (!(*stack) || !(*stack)-> next)
		return ;
	temp = *stack;
	*stack = (*stack)-> next;
	temp -> next = (*stack)-> next;
	(*stack)-> next = temp;
}

void	sa(t_sta *tab, t_list **stack1)
{
	ft_s(stack1);
	tab -> ops.sa += 1;
	tab -> ops.total += 1;
	write(1, "sa\n", 3);
}

void	sb(t_sta *tab, t_list **stack2)
{
	ft_s(stack2);
	tab -> ops.sb += 1;
	tab -> ops.total += 1;
	write(1, "sb\n", 3);
}

void	ss(t_sta *tab, t_list **stack1, t_list **stack2)
{
	ft_s(stack1);
	ft_s(stack2);
	tab -> ops.ss += 1;
	tab -> ops.total += 1;
	write(1, "ss\n", 3);
}
