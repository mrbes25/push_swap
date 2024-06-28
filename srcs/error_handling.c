/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:11:05 by bschmid           #+#    #+#             */
/*   Updated: 2024/06/26 19:11:05 by bschmid          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	error_syntax(char *s)
{
	if (!(*s == '+' || *s == '-' || (*s >= '0' && *s <= '9')))
		return (1);
	if ((*s == '+' || *s == '-') && !(s[1] >= '0' && s[1] <= '9'))
		return (1);
	while (*++s)
	{
		if (!(*s >= '0' && *s <= '9'))
			return (1);
	}
	return (0);
}

static int	error_duplicate(t_node *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->number == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_stack(t_node **stack)
{
	t_node	*tmp;
	t_node	*current;

	if (!*stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->number = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	safety_check(char *s, t_node *a, long n)
{
	if (n < INT_MIN || n > INT_MAX)
		free_errors(&a);
	if (error_syntax(s) != 0)
		free_errors(&a);
	if (error_duplicate(a, n) != 0)
		free_errors(&a);
}

void	free_errors(t_node **a)
{
	free_stack(a);
	ft_printf("Error\n");
	exit(1);
}
