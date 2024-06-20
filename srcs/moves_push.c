/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:55:56 by daduarte          #+#    #+#             */
/*   Updated: 2024/06/20 12:01:26 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *new_a;
	t_stack *new_b;

	if ((*stack_b)->len <= 0)
		return;
	new_b = copy_stack(*stack_b, (*stack_b)->len - 1, 0, 0);
	new_a = copy_stack(*stack_a, (*stack_a)->len + 1, (*stack_b)->stack[0], 1);

	if ((*stack_a)->len > 0)
		free((*stack_a)->stack);
	free(*stack_a);
	*stack_a = new_a;
	free_stack_array(&((*stack_b)->stack));
	free(*stack_b);
	*stack_b = new_b;
	print_move("pa");
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *new_a;
	t_stack *new_b;

	if ((*stack_a)->len <= 0)
		return;
	new_b = copy_stack(*stack_b, (*stack_b)->len + 1, (*stack_a)->stack[0], 1);
	new_a = copy_stack(*stack_a, (*stack_a)->len - 1, 0, 0);

	free_stack_array(&((*stack_a)->stack));
	free(*stack_a);
	*stack_a = new_a;
	free_stack_array(&((*stack_b)->stack));
	free(*stack_b);
	*stack_b = new_b;
	print_move("pb");
}
