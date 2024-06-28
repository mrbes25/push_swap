/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:24:46 by bschmid           #+#    #+#             */
/*   Updated: 2024/06/26 15:24:55 by bschmid          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	init_nodes_a(t_node *a, t_node *b)
{
	set_index(a);
	set_index(b);
	set_target_a(a, b);
	set_cost_a(a, b);
	set_chpst(a);
}

static void	init_nodes_b(t_node *a, t_node *b)
{
	set_index(a);
	set_index(b);
	set_target_b(a, b);
}

static void	move_a_to_b(t_node **a, t_node **b)
{
	t_node	*cheapest;

	cheapest = return_cheapest(*a);
	if (!cheapest)
		return ;
	if (!cheapest->target)
		return ;
	if (cheapest->above_median && cheapest->target->above_median)
		rotate_both(a, b, cheapest);
	else if (!cheapest->above_median && !cheapest->target->above_median)
		rev_rotate_both(a, b, cheapest);
	prep_for_push(a, cheapest, 'a');
	prep_for_push(b, cheapest->target, 'b');
	pb(a, b);
}

static void	move_b_to_a(t_node **a, t_node **b)
{
	prep_for_push(a, ((*b)->target), 'a');
	pa(a, b);
}

void	turk_algo(t_node **a, t_node **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(a, b);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(a, b);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_3(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	set_index(*a);
	smallest_on_top(a);
}
