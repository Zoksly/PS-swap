#include "../../Push_swap/push_swap.h"

void	execute_rotations(t_sta *tab)
{
	while (tab->best_ops.c_rr > 0)
	{
		rr(tab, &tab->stack_a, &tab->stack_b);
		tab->best_ops.c_rr--;
	}
	while (tab->best_ops.c_rrr > 0)
	{
		rrr(tab, &tab->stack_a, &tab->stack_b);
		tab->best_ops.c_rrr--;
	}
	execute_single_rot(tab);
	pb(tab, &tab->stack_a, &tab->stack_b);
}

void	execute_single_rot(t_sta *tab)
{
	while (tab -> best_ops.c_ra-- > 0)
		ra(tab, &tab -> stack_a);
	while (tab -> best_ops.c_rra-- > 0)
		rra(tab, &tab -> stack_a);
	while (tab -> best_ops.c_rb-- > 0)
		rb(tab, &tab -> stack_b);
	while (tab -> best_ops.c_rrb-- > 0)
		rrb(tab, &tab -> stack_b);
}

int		rotations_cost(t_sta *tab, int b_index, int a_index)
{
	free_c_ops(tab);
	if (a_index > tab -> lena / 2)
		tab -> c_ops.c_rra = tab -> lena - a_index;
	else
		tab -> c_ops.c_ra = a_index;
	if (b_index > tab -> lenb / 2)
		tab -> c_ops.c_rrb = tab -> lenb - b_index;
	else
		tab -> c_ops.c_rb = b_index;
	if (tab->c_ops.c_rra > 0 && tab->c_ops.c_rrb > 0)
		return (cost_rrr(tab));
	else if (tab -> c_ops.c_ra > 0 && tab -> c_ops.c_rb > 0)
		return (cost_rr(tab));
	return (tab -> c_ops.c_ra + tab -> c_ops.c_rb + tab -> c_ops.c_rra + tab -> c_ops.c_rrb);
}

void	getnpush_cheapest(t_sta *tab, t_list *stacka)
{
	int		i_a;
	t_track	tra;

	tra.best_cost = INT_MAX;
	tra.best_index_a = -1;
	i_a = 0;
	while (stacka)
	{
		tra.i_target = get_index_target(tab, (long)stacka -> content);
		tra.current_cost = rotations_cost(tab, tra.i_target, i_a);
		if (tra.current_cost < tra.best_cost)
		{
			tra.best_cost = tra.current_cost;
			tra.best_index_a = i_a;
			tab -> best_ops = tab -> c_ops;
		}
		stacka = stacka -> next;
		i_a++;
	}
	execute_rotations(tab);
}

void	ft_turksort(t_sta *tab)
{
	int min_index;
	int cost;

	pb(tab, &tab->stack_a, &tab->stack_b);
	pb(tab, &tab->stack_a, &tab->stack_b);
	while (tab->lena > 3)
		getnpush_cheapest(tab, tab->stack_a);
	ft_threefast(tab);
	push_to_a(tab);
	min_index = get_min_index(tab->stack_a);
	if (min_index <= tab->lena / 2)
	{
		cost = min_index;
		while (cost-- > 0)
			ra(tab, &tab->stack_a);
	}
	else
	{
		cost = tab->lena - min_index;
		while (cost-- > 0)
			rra(tab, &tab->stack_a);
	}
}