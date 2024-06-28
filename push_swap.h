/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:43:09 by bschmid           #+#    #+#             */
/*   Updated: 2024/06/27 09:37:20 by bschmid          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "my_lib/my_lib.h"
# include <limits.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_node
{
	int				number;
	int				index;
	int				cost;
	bool			above_median;
	bool			cheapest;
	struct s_node	*next;
	struct s_node	*prev;
	struct s_node	*target;
}					t_node;

// ***** MAIN *****

// main
int					main(int argc, char **argv);

// ***** COMMANDS *****

// push
void				pa(t_node **stack_a, t_node **stack_b);
void				pb(t_node **stack_a, t_node **stack_b);

// reverse_rotate
void				rra(t_node **stack_a);
void				rrb(t_node **stack_b);
void				rrr(t_node **stack_a, t_node **stack_b);
void				rev_rotate_both(t_node **a, t_node **b, t_node *cheapest);

// rotate
void				ra(t_node **stack_a);
void				rb(t_node **stack_b);
void				rr(t_node **stack_a, t_node **stack_b);
void				rotate_both(t_node **a, t_node **b, t_node *cheapest);

// swappedyswaps
void				sa(t_node **stack_a);
void				sb(t_node **stack_b);
void				ss(t_node **stack_a, t_node **stack_b);

// ***** PUSH_SWAP *****

// algo_atob
void				set_target_a(t_node *a, t_node *b);
void				set_cost_a(t_node *a, t_node *b);

// algo_btoa
void				set_target_b(t_node *a, t_node *b);

// check_utils
bool				stack_sorted(t_node *stack);
int					sorted_check(t_node **list);

// dll_functions
t_node				*add_to_empty(int data);
t_node				*add_at_start(t_node *head, int data);
t_node				*add_at_end(t_node *head, int data);
void				init_dll(int argc, char **argv, t_node **head, int start);

// error_handling
void				safety_check(char *s, t_node *a, long n);
void				free_errors(t_node **a);
void				free_stack(t_node **stack);
// find_utils
t_node				*find_biggest(t_node *stack);
t_node				*find_smallest(t_node *stack);
t_node				*find_last(t_node *stack);
int					stack_len(t_node *stack);
t_node				*return_cheapest(t_node *stack);

// general_utils
void				set_index(t_node *stack);
void				set_chpst(t_node *stack);
void				prep_for_push(t_node **stack, t_node *top_node,
						char stack_name);
void				smallest_on_top(t_node **a);

// tiny_algo
void				sort_3(t_node **a);

// turk_sort
void				turk_algo(t_node **a, t_node **b);

#endif
