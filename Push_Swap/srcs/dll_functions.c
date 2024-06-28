/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:42:07 by bschmid           #+#    #+#             */
/*   Updated: 2024/06/26 16:42:14 by bschmid          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*add_to_empty(int number)
{
	t_node	*temp;

	temp = malloc(sizeof(t_node));
	if (temp == NULL)
		return (NULL);
	temp->prev = NULL;
	temp->number = number;
	temp->next = NULL;
	return (temp);
}

t_node	*add_at_start(t_node *head, int number)
{
	t_node	*new_p;

	new_p = add_to_empty(number);
	if (new_p == NULL)
		return (NULL);
	else
	{
		new_p->next = head;
		if (head != NULL)
			head->prev = new_p;
		return (new_p);
	}
}

t_node	*add_at_end(t_node *head, int number)
{
	t_node	*new_p;
	t_node	*last;

	new_p = add_to_empty(number);
	if (new_p == NULL)
		return (NULL);
	else
	{
		if (head == NULL)
			return (new_p);
		last = head;
		while (last->next != NULL)
			last = last->next;
		last->next = new_p;
		new_p->prev = last;
		return (head);
	}
}

void	init_dll(int argc, char **argv, t_node **head, int start)
{
	long	temp;
	int		i;

	i = start;
	while (i < argc)
	{
		temp = atol(argv[i]);
		safety_check(argv[i], *head, temp);
		if (*head == NULL)
			*head = add_to_empty(temp);
		else
		{
			*head = add_at_end(*head, temp);
			if (*head == NULL)
				return ;
		}
		i++;
	}
}
