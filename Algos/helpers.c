/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanco- <vblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 18:13:39 by vblanco-          #+#    #+#             */
/*   Updated: 2026/03/03 19:33:52 by vblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Push_swap/push_swap.h"

int	ft_chunk_size(int i)
{
	if (i > 20 && i < 150)
		return (i / 6);
	else if (i > 150 && i < 300)
		return (i / 15);
	else if (i > 300)
		return (i / 19);
	else
		return (i / 2);
}

int	get_index(t_list *node, int *array, int nb_elements)
{
	int	i;

	i = 0;
	while (i < nb_elements)
	{
		if (array[i] == (long)node -> content)
			return (i);
		i++;
	}
	return (-1);
}

//sorting array
void	sort_array(int *array, int lena)
{
	int	i;
	int	flag;
	int	temp;

	flag = 1;
	while (flag == 1)
	{
		flag = 0;
		i = 0;
		while (i < lena - 1)
		{
			if (array[i] > array[i + 1])
			{
				flag = 1;
				temp = array [i + 1];
				array [i + 1] = array[i];
				array[i] = temp;
			}
			i++;
		}
	}
}

//copy stack to an array
int	*stack_to_array(t_list *stack, int lena, int sort)
{
	int	*array;
	int	i;

	array = ft_calloc(1, sizeof(int) * lena);
	if (array == NULL)
		return (0);
	i = 0;
	while (stack)
	{
		array[i] = (long)stack -> content;
		stack = stack -> next;
		i++;
	}
	if (sort == 1)
		sort_array(array, lena);
	return (array);
}

int	get_max_index(t_list *stack)
{
	t_list	*current;
	t_list	*max;
	int		i;
	int		imax;

	current = stack;
	max = stack;
	i = 0;
	imax = 0;
	while (current)
	{
		if ((long)current -> content > (long)max -> content)
		{
			max = current;
			imax = i;
		}
		current = current -> next;
		i++;
	}
	return (imax);
}
