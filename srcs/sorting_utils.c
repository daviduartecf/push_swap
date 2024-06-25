/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 10:50:52 by daduarte          #+#    #+#             */
/*   Updated: 2024/06/25 10:57:41 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	if (stack->len <= 1)
		return (1);
	while (i < stack->len - 1)
	{
		if (stack->stack[i] > stack->stack[i + 1])
			return (0);
		i ++;
	}
	return (1);
}

int	position_in_stackb(t_stack *stack, int value)
{
	int	i;
	int	max_index;
	int	min_index;

	i = 0;
	max_index = get_max_index(stack);
	min_index = get_min_index(stack);
	if (is_min(stack, value))
		return (min_index + 1);
	if (is_max(stack, value))
		return (max_index);
	while (i < stack->len - 1)
	{
		if (stack->stack[i] > value && value > stack->stack[i + 1])
			return (i + 1);
		i++;
	}
	return (stack->len);
}

int	position_in_stacka(t_stack *stack, int value)
{
	int	i;
	int	max_index;
	int	min_index;

	i = 0;
	min_index = get_min_index(stack);
	max_index = get_max_index(stack);
	if (is_min(stack, value))
		return (min_index);
	if (is_max(stack, value))
		return (max_index + 1);
	while (i < stack->len - 1)
	{
		if (stack->stack[i] < value && value < stack->stack[i + 1])
			return (i + 1);
		i ++;
	}
	return (stack->len);
}

int	find_insert_position(t_stack *stack_a, int value)
{
	int	pos;

	pos = 0;
	while (pos < stack_a->len && stack_a->stack[pos] < value)
		pos++;
	return (pos);
}

void	insert_elem(t_stack **stack_a, t_stack **stack_b, int b_ind, int a_pos)
{
	rot_both(stack_a, stack_b, &a_pos, &b_ind);
	if (b_ind <= (*stack_b)->len / 2)
	{
		while (b_ind-- > 0)
			rb(*stack_b);
	}
	else
	{
		while (b_ind++ < (*stack_b)->len)
			rrb(*stack_b);
	}
	if (a_pos <= (*stack_a)->len / 2)
	{
		while (a_pos-- > 0)
			ra(*stack_a);
	}
	else
	{
		while (a_pos++ < (*stack_a)->len)
			rra(*stack_a);
	}
	pa(stack_a, stack_b);
}
