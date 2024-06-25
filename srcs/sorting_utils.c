/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 10:50:52 by daduarte          #+#    #+#             */
/*   Updated: 2024/06/25 12:23:03 by daduarte         ###   ########.fr       */
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

/* MOVE ELEMENT FROM STACK A TO STACK B */
/*	first see if it is possible to rotate A and B
	then rotate stack A to put it index 0 the cheapest number
	then rotate stack B to prepare it to receive the number
	finally push the number to the correct position in B */

void	move_elem(t_stack **stack_a, t_stack **stack_b, int a_ind, int b_pos)
{
	rot_both(stack_a, stack_b, &a_ind, &b_pos);
	if (a_ind <= (*stack_a)->len / 2)
	{
		while (a_ind-- > 0)
			ra(*stack_a);
	}
	else
	{
		while (a_ind++ < (*stack_a)->len)
			rra(*stack_a);
	}
	if (b_pos <= (*stack_b)->len / 2)
	{
		while (b_pos-- > 0)
			rb(*stack_b);
	}
	else
	{
		while (b_pos++ < (*stack_b)->len)
			rrb(*stack_b);
	}
	pb(stack_a, stack_b);
}

/* MOVE ELEMENT FROM STACK B TO STACK A */
/*	first see if it is possible to rotate A and B
	then rotate stack B to put it index 0 the cheapest number
	then rotate stack A to prepare it to receive the number
	finally push the number to the correct position in A */

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
