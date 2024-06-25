/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_price.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:55:56 by daduarte          #+#    #+#             */
/*   Updated: 2024/06/25 16:13:13 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* CALCULATE MOVES BOTH ROTATE MOVES */
/*	check if the index A & index B are both in the same half of the stack
	if they are, the common moves are equal to the largest index */

int	common_moves(t_stack *stack_a, t_stack *stack_b, int a_ind, int b_pos)
{
	int	total;

	total = 0;
	if ((a_ind <= stack_a->len / 2) && (b_pos <= stack_b-> len / 2))
	{
		if (a_ind > b_pos)
			total = a_ind;
		else
			total = b_pos;
	}
	else if ((a_ind > stack_a->len / 2) && (b_pos > stack_b->len / 2))
	{
		if ((stack_a->len - a_ind) > (stack_b->len - b_pos))
			total = stack_a->len - a_ind;
		else
			total = stack_b->len - b_pos;
	}
	return (total);
}

/* CALCULATE TOTAL MOVES NEEDED TO ROTATE STACKS TO THE BEST POSITION */
/*	common moves -> if the number is on top using common moves, perfect
	if the number isn't still in position, total moves equal:
		-> index of number in A + (len - index of number in B)
		or
		-> (len - index of number in A) + index of number in B*/

int	total_moves(t_stack *stack_a, t_stack *stack_b, int a_index, int b_pos)
{
	int	total;

	total = common_moves(stack_a, stack_b, a_index, b_pos);
	if ((a_index <= stack_a->len / 2) && (b_pos > stack_b->len / 2))
		total = a_index + (stack_b->len - b_pos);
	else if ((a_index > stack_a->len / 2) && (b_pos <= stack_b->len / 2))
		total = (stack_a->len - a_index) + b_pos;
	return (total);
}

/* FIND CHEAPEST NUMBER IN STACK A TO PASS TO STACK B */
/*	calculates cost of passing a number in the right order to stack B
	the cost is equal to the number of moves to get the number to index 0
	plus the number of moves to prepare the stack B to recive the number
	in the correct position
		-a_index is the index of the cheapest number in stack A
		-b_position is the best position in stack B to put that number */

int	cheapest(t_stack *stack_a, t_stack *stack_b, int *a_index, int *b_pos)
{
	int	i;
	int	b_index;
	int	min_cost;
	int	total_cost;

	i = 0;
	b_index = 0;
	total_cost = 0;
	min_cost = 2147483647;
	while (i < stack_a->len)
	{
		b_index = position_in_stackb(stack_b, stack_a->stack[i]);
		total_cost = total_moves(stack_a, stack_b, i, b_index);
		if (total_cost < min_cost)
		{
			min_cost = total_cost;
			*a_index = i;
			*b_pos = b_index;
		}
		i ++;
	}
	return (min_cost);
}

/* FIND CHEAPEST NUMBER IN STACK B TO PASS TO STACK A */
/*	calculates cost of passing a number in the right order to stack A
	the cost is equal to the number of moves to get the number to index 0
	plus the number of moves to prepare the stack A to recive the number
	in the correct position
		-b_index is the index of the cheapest number in stack B
		-a_position is the best position in stack A to put that number */

int	cheapest_a(t_stack *stack_a, t_stack *stack_b, int *b_ind, int *a_pos)
{
	int	i;
	int	a_index;
	int	min_cost;
	int	total_cost;

	i = 0;
	a_index = 0;
	total_cost = 0;
	min_cost = 2147483647;
	while (i < stack_b->len)
	{
		a_index = position_in_stacka(stack_a, stack_b->stack[i]);
		total_cost = total_moves(stack_a, stack_b, a_index, i);
		if (total_cost < min_cost)
		{
			min_cost = total_cost;
			*b_ind = i;
			*a_pos = a_index;
		}
		i++;
	}
	return (min_cost);
}

/* BEST POSITION FOR A NUMBER IN STACK B */
/*	calculates the best position for a value of stack A to be placed in stack B
	the best position should be bellow a larger value and above a smaller value
	this ensures the descending order in stack B */

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
