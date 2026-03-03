/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanco- <vblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 18:56:52 by vblanco-          #+#    #+#             */
/*   Updated: 2026/03/03 18:56:52 by vblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Calcul of disorder
float	ft_compute_disorder(t_sta *tab, int nb_node)
{
	t_list	*current;
	t_list	*next;
	int		miss;
	int		succ;

	miss = 0;
	succ = 0;
	current = tab -> stack_a;
	while (nb_node && current)
	{
		next = current -> next;
		while (next)
		{
			if ((current -> content) > next -> content)
				miss++;
			else if ((current -> content) < next -> content)
				succ++;
			next = next -> next;
		}
		current = current -> next;
		nb_node--;
	}
	if ((miss + succ) == 0)
		return (0);
	return ((float)miss / (float)(miss + succ));
}

//Initialisation of stack and return her lenght + check if they are doubles
int	ft_init_stack(t_sta *tab, char **args)
{
	t_list		*new_node;
	int			nb_node;
	long		nbr;

	nb_node = 0;
	while (args[nb_node])
	{
		if (ft_isnumber(args[nb_node]) == 0)
			return (0);
		nbr = ft_atol(args[nb_node]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			return (0);
		new_node = ft_lstnew((void *)(long)nbr);
		if (!new_node)
			return (0);
		ft_lstadd_back(&(tab -> stack_a), new_node);
		nb_node++;
	}
	if (check_doubles(tab -> stack_a) == 0)
		return (0);
	return (nb_node);
}

//Parsing of mode(s) and update tab -> mode
int	ft_searchmode(char **av, t_sta *tab, int i_arg, int ac)
{
	while (av[i_arg] != NULL && !(ft_isnumber(av[i_arg])) && i_arg < ac - 1)
	{
		if (ft_strcmp(av[i_arg], "--simple") == 0)
			tab -> mode = SIMPLE;
		else if (ft_strcmp(av[i_arg], "--adaptive") == 0)
			tab -> mode = ADAPTIVE;
		else if (ft_strcmp(av[i_arg], "--medium") == 0)
			tab -> mode = MEDIUM;
		else if (ft_strcmp(av[i_arg], "--complex") == 0)
			tab -> mode = COMPLEX;
		else if (ft_strcmp(av[i_arg], "--bench") == 0)
			tab -> benchm = 1;
		else
			return (0);
		i_arg++;
	}
	return (i_arg);
}

//Parsing if they are modes, if they aren't setting default and return 
int	ft_parse_mode(char **argv, t_sta *tab, int ac)
{
	int	i_arg;

	i_arg = 1;
	if (argv[1][0] >= '0' && argv[1][0] <= '9')
	{
		tab -> benchm = 0;
		tab -> mode = ADAPTIVE;
		return (1);
	}
	i_arg = ft_searchmode(argv, tab, i_arg, ac);
	return (i_arg);
}

int	main(int argc, char **argv)
{
	t_sta	*tab;
	char	**args;

	if (argc < 2)
		return (0);
	tab = calloc(1, sizeof(t_sta));
	if (!tab)
		return (0);
	args = ft_init(argv, argc, tab);
	if (!args)
		return (0);
	tab -> disorder = ft_compute_disorder(tab, tab -> lena);
	ft_choose_algo(tab);
	ft_free(args, tab);
	return (0);
}
