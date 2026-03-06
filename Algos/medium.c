/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanco- <vblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 18:13:44 by vblanco-          #+#    #+#             */
/*   Updated: 2026/03/03 18:13:44 by vblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Push_swap/push_swap.h"

//search the first element that be in the target chunk
int	find_chunk_in_stack(t_sta *tab, int *sorted_array, int chk_targ, int chk_sz)
{
	int		index;
	int		chunk_start;
	int		chunk_end;
	int		i_node;
	t_list	*stack;

	stack = tab->stack_a;
	chunk_start = chk_sz * chk_targ;
	chunk_end = chunk_start + chk_sz - 1;
	i_node = 0;
	while (stack)
	{
		index = get_index(stack, sorted_array, tab->lena + tab->lenb);
		if (index >= chunk_start && index <= chunk_end)
			return (i_node);
		stack = stack->next;
		i_node++;
	}
	return (-1);
}

//push stack_a to tack_b, in chunks
void	push_chunk(t_sta *tab, int nb_node, int *array, int chunk_size)
{
    int i_chunks;
    int n_index;

    i_chunks = 0;
    while (i_chunks <= nb_node / chunk_size)
    {
        while ((n_index = find_chunk_in_stack(tab, array, i_chunks, chunk_size)) != -1)
        {
            if (n_index == 0)
                pb(tab, &tab -> stack_a, &tab -> stack_b);
            else if (n_index <= (int)tab -> lena / 2)
                ra(tab, &tab -> stack_a);
            else
                rra(tab, &tab -> stack_a);
        }
        i_chunks++;
    }
}

void	ft_medium(t_sta *tab, int nb_node)
{
	int		chunk_size;
	t_list	*stacka;
	int		*array;
	int		max_index;

	chunk_size = ft_chunk_size(nb_node);
	stacka = tab -> stack_a;
	array = stack_to_array(stacka, tab -> lena, 1);
	if (!array)
		return ;
	push_chunk(tab, nb_node, array, chunk_size);
	while (tab -> stack_b)
	{
		max_index = get_max_index(tab -> stack_b);
		if (max_index == 0)
			pa(tab, &tab -> stack_b, &tab -> stack_a);
		else if (max_index < (int)tab -> lenb / 2)
			rb(tab, &tab -> stack_b);
		else
			rrb(tab, &tab -> stack_b);
	}
	free(array);
}
