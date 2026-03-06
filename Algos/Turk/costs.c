#include "../../Push_swap/push_swap.h"

int	cost_rrr(t_sta *tab)
{
	if (tab -> c_ops.c_rra != 0 && tab -> c_ops.c_rrb != 0)
	{
		if (tab -> c_ops.c_rra == tab -> c_ops.c_rrb)
		{
			tab -> c_ops.c_rrr = tab -> c_ops.c_rra;
			tab -> c_ops.c_rrb = 0;
			tab -> c_ops.c_rra = 0;
		}
		else if (tab -> c_ops.c_rra > tab -> c_ops.c_rrb)
		{
			tab -> c_ops.c_rrr = tab -> c_ops.c_rrb;
			tab -> c_ops.c_rra = tab -> c_ops.c_rra - tab -> c_ops.c_rrb;
			tab -> c_ops.c_rrb = 0;
		}
		else if (tab -> c_ops.c_rrb > tab -> c_ops.c_rra)
		{
			tab -> c_ops.c_rrr = tab -> c_ops.c_rra;
			tab -> c_ops.c_rrb = tab -> c_ops.c_rrb - tab -> c_ops.c_rra;
			tab -> c_ops.c_rra = 0;
		}
	}
	return (tab->c_ops.c_rra + tab->c_ops.c_rrb + tab->c_ops.c_rrr);
}

int	cost_rr(t_sta *tab)
{
	if (tab -> c_ops.c_ra != 0 && tab -> c_ops.c_rb != 0)
	{
		if (tab -> c_ops.c_ra == tab -> c_ops.c_rb)
		{
			tab -> c_ops.c_rr = tab -> c_ops.c_ra;
			tab -> c_ops.c_rb = 0;
			tab -> c_ops.c_ra = 0;
		}
		else if (tab -> c_ops.c_ra > tab -> c_ops.c_rb)
		{
			tab -> c_ops.c_rr = tab -> c_ops.c_rb;
			tab -> c_ops.c_ra = tab -> c_ops.c_ra - tab -> c_ops.c_rb;
			tab -> c_ops.c_rb = 0;
		}
		else if (tab -> c_ops.c_rb > tab -> c_ops.c_ra)
		{
			tab -> c_ops.c_rr = tab -> c_ops.c_ra;
			tab -> c_ops.c_rb = tab -> c_ops.c_rb - tab -> c_ops.c_ra;
			tab -> c_ops.c_ra = 0;
		}
	}
	return (tab->c_ops.c_ra + tab->c_ops.c_rb + tab->c_ops.c_rr);
}
