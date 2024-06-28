/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:12:56 by bschmid           #+#    #+#             */
/*   Updated: 2024/06/26 15:13:00 by bschmid          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_index(t_node *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		++i;
	}
}

void	set_chpst(t_node *stack)
{
	long	chpst;
	t_node	*cheapest_node;

	if (!stack)
		return ;
	chpst = LONG_MAX;
	while (stack)
	{
		if (stack->cost < chpst)
		{
			chpst = stack->cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	prep_for_push(t_node **stack, t_node *top_node, char stack_name)
{
	if (!stack || !top_node)
		return ;
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
			{
				ra(stack);
			}
			else
			{
				rra(stack);
			}
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

void	smallest_on_top(t_node **a)
{
	while ((*a)->number != find_smallest(*a)->number)
	{
		if (find_smallest(*a)->above_median)
			ra(a);
		else
			rra(a);
	}
}
