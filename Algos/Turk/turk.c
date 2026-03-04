#include "../../Push_swap/push_swap.h"

int		rotations_cost(t_sta *tab, int b_index, int a_index)
{
	int		a_cost;
	int		b_cost;

	if (a_index > tab -> lena / 2)
		a_cost = tab -> lena - a_index;
	else
		a_cost = a_index;
	if (b_index > tab -> lenb / 2)
		b_cost = tab -> lenb - b_index;
	else
		b_cost = b_index;
	tab -> c_ops -> r
}

void	get_target(t_sta *tab)
{
	int		i;
	int		i_target;
	t_list	*stacka;

	i = 0;
	while (i <= tab -> lena)
	{
		i_target = get_index_target(tab, stacka -> content);

		stacka = stacka -> next;
		i++;
	}
}

void	ft_turksort(t_sta *tab)
{


	pb(tab, &tab -> stack_a, &tab -> stack_b);
	pb(tab, &tab -> stack_a, &tab -> stack_b);
	while (tab -> lena > 3)
	{
		get_target(tab);
	}
}


a : 51 8 6 9 40 35 21 4 25
b : 7 2 1 10