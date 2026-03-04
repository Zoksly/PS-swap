#include "../../Push_swap/push_swap.h"

int	get_index_target(t_sta *tab, int target)
{
	int		i;
	int		index;
	long	temp;
	t_list	*stack;

	i = -1;
	stack = tab -> stack_b;
	temp = LONG_MIN;
	while (i <= tab -> lenb)
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



a : 51 8 6 9 40 35 21 4 25
b : 7 2 1 10