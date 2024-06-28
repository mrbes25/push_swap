/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:08:58 by bschmid           #+#    #+#             */
/*   Updated: 2024/06/26 15:09:05 by bschmid          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	stack_sorted(t_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->number > stack->next->number)
			return (false);
		stack = stack->next;
	}
	return (true);
}

int	sorted_check(t_node **list)
{
	t_node	*ptr;

	if (*list == NULL)
		return (1);
	ptr = (*list)->next;
	while (ptr != *list)
	{
		if (ptr->number > ptr->next->number)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}
