/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rotate_both.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 09:59:55 by daduarte          #+#    #+#             */
/*   Updated: 2024/06/25 12:40:07 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* ROTATE BOTH STACKS IF POSSIBLE */
/*	it only rotates both if both requisites are met:
		-index a AND b are higher than 0 (the number is not in index 0) */

void	rot_both(t_stack **stack_a, t_stack **stack_b, int *a_ind, int *b_pos)
{
	while (*a_ind > 0 && *b_pos > 0 && *a_ind <= (*stack_a)->len / 2
		&& *b_pos <= (*stack_b)->len / 2)
	{
		rr(*stack_a, *stack_b);
		(*a_ind)--;
		(*b_pos)--;
	}
	while (*a_ind < (*stack_a)->len && *b_pos < (*stack_b)->len
		&& *a_ind > (*stack_a)->len / 2 && *b_pos > (*stack_b)->len / 2)
	{
		rrr(*stack_a, *stack_b);
		(*a_ind)++;
		(*b_pos)++;
	}
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	temp;

	i = 0;
	temp = stack_a->stack[0];
	while (i < stack_a->len - 1)
	{
		stack_a->stack[i] = stack_a->stack[i + 1];
		i ++;
	}
	stack_a->stack[stack_a->len - 1] = temp;
	i = 0;
	temp = stack_b->stack[0];
	while (i < stack_b->len - 1)
	{
		stack_b->stack[i] = stack_b->stack[i + 1];
		i ++;
	}
	stack_b->stack[stack_b->len - 1] = temp;
	print_move("rr");
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	temp;

	i = stack_a->len - 1;
	temp = stack_a->stack[stack_a->len - 1];
	while (i > 0)
	{
		stack_a->stack[i] = stack_a->stack[i - 1];
		i --;
	}
	stack_a->stack[0] = temp;
	i = stack_b->len - 1;
	temp = stack_b->stack[stack_b->len - 1];
	while (i > 0)
	{
		stack_b->stack[i] = stack_b->stack[i - 1];
		i --;
	}
	stack_b->stack[0] = temp;
	print_move("rrr");
}
