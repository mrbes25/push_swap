/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:15:41 by bschmid           #+#    #+#             */
/*   Updated: 2024/06/26 15:15:41 by bschmid          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_3(t_node **a)
{
	t_node	*biggest;

	biggest = find_biggest(*a);
	if (biggest == *a)
		ra(a);
	else if (biggest == (*a)->next)
		rra(a);
	if ((*a)->number > (*a)->next->number)
		sa(a);
}
