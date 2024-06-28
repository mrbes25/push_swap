/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:29:18 by bschmid           #+#    #+#             */
/*   Updated: 2024/06/26 15:29:18 by bschmid          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push(t_node **dest, t_node **source)
{
	t_node	*to_push;

	if (!*source)
		return ;
	to_push = *source;
	*source = (*source)->next;
	if (*source)
		(*source)->prev = NULL;
	to_push->prev = NULL;
	if (!*dest)
	{
		*dest = to_push;
		to_push->next = NULL;
	}
	else
	{
		to_push->next = *dest;
		to_push->next->prev = to_push;
		*dest = to_push;
	}
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	push(stack_b, stack_a);
	ft_printf("pb\n");
}

void	pa(t_node **stack_a, t_node **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pa\n");
}
