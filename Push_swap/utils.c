/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanco- <vblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 18:56:02 by vblanco-          #+#    #+#             */
/*   Updated: 2026/03/03 18:56:45 by vblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(char **args, t_sta *tab)
{
	if (tab -> stack_a)
		ft_lstclear(&tab -> stack_a, NULL);
	if (tab -> stack_b)
		ft_lstclear(&tab -> stack_b, NULL);
	if (tab -> need_free == 1)
		free(args);
	free(tab);
}

//check if the stack is sorted
int	is_sorted_stack(t_list *stack)
{
	while (stack && stack -> next)
	{
		if ((long) stack -> content > (long) stack -> next -> content)
			return (0);
		stack = stack -> next;
	}
	return (1);
}

//Check doubles in stack
int	check_doubles(t_list *stack)
{
	int		i;
	t_list	*nb;
	t_list	*tmp;

	i = 0;
	nb = stack;
	while (nb != NULL)
	{
		tmp = nb -> next;
		while (tmp)
		{
			if ((long)nb -> content == (long)tmp -> content)
				return (0);
			tmp = tmp -> next;
		}
		nb = nb -> next;
		i++;
	}
	return (1);
}

char	**ft_init(char **argv, int argc, t_sta *tab)
{
	int		i_arg;
	char	**args;

	args = NULL;
	i_arg = ft_parse_mode(argv, tab, argc);
	if (i_arg == 0)
		return (ft_free(args, tab), ft_putstr_fd("Error\n", 2), NULL);
	if (argc == i_arg + 1)
	{
		args = ft_split(argv[i_arg], ' ');
		tab -> need_free = 1;
	}
	else
		args = argv + i_arg;
	tab -> lena = ft_init_stack(tab, args);
	if (tab -> lena == 0)
		return (ft_free(args, tab), ft_putstr_fd("Error\n", 2), NULL);
	return (args);
}
