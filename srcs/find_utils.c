/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:12:21 by bschmid           #+#    #+#             */
/*   Updated: 2024/06/26 15:12:35 by bschmid          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*find_biggest(t_node *stack)
{
	long	biggest;
	t_node	*biggest_node;

	if (!stack)
		return (NULL);
	biggest = LONG_MIN;
	while (stack)
	{
		if (stack->number > biggest)
		{
			biggest = stack->number;
			biggest_node = stack;
		}
		stack = stack->next;
	}
	return (biggest_node);
}

t_node	*find_smallest(t_node *stack)
{
	long	smallest;
	t_node	*smallest_node;

	if (!stack)
		return (NULL);
	smallest = LONG_MAX;
	while (stack)
	{
		if (stack->number < smallest)
		{
			smallest = stack->number;
			smallest_node = stack;
		}
		stack = stack->next;
	}
	return (smallest_node);
}

t_node	*find_last(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

int	stack_len(t_node *stack)
{
	int	count;

	if (!stack)
		return (0);
	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

t_node	*return_cheapest(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
