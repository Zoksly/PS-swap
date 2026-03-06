/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanco- <vblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 18:52:48 by vblanco-          #+#    #+#             */
/*   Updated: 2026/03/03 18:52:48 by vblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"
# include "../ft_dprintf/ft_dprintf.h"

typedef enum s_mode
{
	ADAPTIVE,
	SIMPLE,
	MEDIUM,
	COMPLEX
}	t_mode;

typedef struct s_ops
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total;
}	t_ops;

typedef struct s_count_ops
{
	int	c_ra;
	int	c_rb;
	int	c_rra;
	int	c_rrb;
	int	c_rrr;
	int	c_rr;
}	c_ops;

typedef struct s_track
{
	int	best_cost;
	int	best_index_a;
	int	current_cost;
	int	i_target;
}	t_track;

typedef struct s_sta
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		benchm;
	t_mode	mode;
	c_ops	c_ops;
	c_ops	best_ops;
	float	disorder;
	int		need_free;
	int		lena;
	int		lenb;
	t_ops	ops;
}	t_sta;

/* Main & Utils */
int		main(int argc, char **argv);
int		ft_init_stack(t_sta *tab, char **args);
void	ft_free(char **args, t_sta *tab);
float	compute_disorder(t_sta *tab, int i);
void	ft_choose_algo(t_sta *tab);
void	get_benchmark(t_sta *tab);
int		is_sorted_stack(t_list *stack);
int		check_doubles(t_list *stack);
int		ft_parse_mode(char **argv, t_sta *tab, int ac);
int		ft_searchmode(char **av, t_sta *tab, int i_arg, int ac);
char	**ft_init(char **argv, int argc, t_sta *tab);

/* Operations */
void	sa(t_sta *tab, t_list **stack1);
void	sb(t_sta *tab, t_list **stack2);
void	ss(t_sta *tab, t_list **stack1, t_list **stack2);
void	pa(t_sta *tab, t_list **stackb, t_list **stacka);
void	pb(t_sta *tab, t_list **stacka, t_list **stackb);
void	ra(t_sta *tab, t_list **stacka);
void	rb(t_sta *tab, t_list **stackb);
void	rr(t_sta *tab, t_list **stacka, t_list **stackb);
void	rra(t_sta *tab, t_list **stacka);
void	rrb(t_sta *tab, t_list **stackb);
void	rrr(t_sta *tab, t_list **stacka, t_list **stackb);

/* Algo Simple */
void	ft_index_stack(t_list *stack);
int		get_min_index(t_list *stack);
int		get_max_index(t_list *stack);
void	ft_simple(t_sta *tab);

/* Helpers Functions */
int		ft_chunk_size(int i);
int		get_index(t_list *node, int *array, int nb_elements);
void	sort_array(int *array, int size);
int		*stack_to_array(t_list *stack, int size, int sort);

/* Algo Medium */
int		find_chunk_in_stack(t_sta *tab, int *sorted_array, int target_chunk,
			int chunk_size);
void	push_chunk(t_sta *tab, int nb_node, int *array, int chunk_size);
void	ft_medium(t_sta *tab, int nb_node);

/* Algo Complex (Radix Sort) */
int		get_max_bits(int lena, int *array);
void	check_bits(t_sta *tab, int i_bits, int *array, int nb_node);
void	radix_sort(t_sta *tab);

/* Turk Sort (Cost-Based Algorithm) */
void	ft_turksort(t_sta *tab);
void	push_to_a(t_sta *tab);
int		get_target_in_a(t_sta *tab, int target);
int		get_index_target(t_sta *tab, int target);
void	free_c_ops(t_sta *tab);
int		cost_rrr(t_sta *tab);
int		cost_rr(t_sta *tab);
void	execute_rotations(t_sta *tab);
void	execute_single_rot(t_sta *tab);

/* Hardcodes for 3 and 5 numbers */
void	small_sorters(t_sta *tab);
void	ft_threefast(t_sta *tab);
void	ft_fivast(t_sta *tab);

#endif
