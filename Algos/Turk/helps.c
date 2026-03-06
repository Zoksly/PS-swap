#include "../../Push_swap/push_swap.h"

void	push_to_a(t_sta *tab)
{
	int	a_target;
	int	cost;

	while (tab->lenb > 0)
	{
		a_target = get_target_in_a(tab, (long)tab -> stack_b -> content);
		if (a_target <= tab->lena / 2)
		{
			cost = a_target;
			while (cost-- > 0)
				ra(tab, &tab->stack_a);
		}
		else
		{
			cost = tab->lena - a_target;
			while (cost-- > 0)
				rra(tab, &tab->stack_a);
		}
		pa(tab, &tab->stack_b, &tab->stack_a);
	}
}


int	get_target_in_a(t_sta *tab, int target)
{
	int		i;
	int		index;
	long	temp;
	t_list	*stack;

	i = 0;
	index = -1;
	stack = tab -> stack_a;
	temp = LONG_MAX;
	while (stack)
	{
		if ((long)stack -> content > target && (long)stack -> content < temp)
		{
			index = i;
			temp = (long)stack -> content;
		}
		stack = stack -> next;
		i++;
	}
	if (index == -1)
		return (get_min_index(tab -> stack_a));
	return (index);
}

int	get_index_target(t_sta *tab, int target)
{
	int		i;
	int		index;
	long	temp;
	t_list	*stack;

	i = 0;
	index = -1;
	stack = tab -> stack_b;
	temp = LONG_MIN;
	while (stack != NULL)
	{
		if ((long)stack -> content < target && (long)stack -> content > temp)
		{
			index = i;
			temp = (long)stack -> content;
		}
		stack = stack -> next;
		i++;
	}
	if (index == -1)
		return (get_max_index(tab -> stack_b));
	return (index);
}


void	free_c_ops(t_sta *tab)
{
	tab->c_ops.c_ra = 0;
	tab->c_ops.c_rb = 0;
	tab->c_ops.c_rra = 0;
	tab->c_ops.c_rrb = 0;
	tab->c_ops.c_rr = 0;
	tab->c_ops.c_rrr = 0;
}
