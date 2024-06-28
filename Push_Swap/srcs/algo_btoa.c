/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_btoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:43:32 by bschmid           #+#    #+#             */
/*   Updated: 2024/06/26 14:43:32 by bschmid          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_target_b(t_node *a, t_node *b)
{
	t_node	*current_a;
	t_node	*target_node;
	long	best_match;

	while (b)
	{
		best_match = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->number > b->number && current_a->number < best_match)
			{
				best_match = current_a->number;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match == LONG_MAX)
			b->target = find_smallest(a);
		else
			b->target = target_node;
		b = b->next;
	}
}
