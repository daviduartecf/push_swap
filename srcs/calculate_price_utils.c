/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_price_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:56:56 by daduarte          #+#    #+#             */
/*   Updated: 2024/06/25 15:37:07 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_max_index(t_stack *stack)
{
	int	i;
	int	max_index;

	i = 1;
	max_index = 0;
	while (i < stack->len)
	{
		if (stack->stack[i] > stack->stack[max_index])
			max_index = i;
		i++;
	}
	return (max_index);
}

int	get_min_index(t_stack *stack)
{
	int	i;
	int	min_index;

	i = 1;
	min_index = 0;
	while (i < stack->len)
	{
		if (stack->stack[i] < stack->stack[min_index])
			min_index = i;
		i++;
	}
	return (min_index);
}

int	is_min(t_stack *stack, int value)
{
	int	i;

	i = 0;
	while (i < stack->len)
	{
		if (stack->stack[i] < value)
			return (0);
		i ++;
	}
	return (1);
}

int	is_max(t_stack *stack, int value)
{
	int	i;

	i = 0;
	while (i < stack->len)
	{
		if (stack->stack[i] > value)
			return (0);
		i ++;
	}
	return (1);
}

/* BEST POSITION FOR A NUMBER IN STACK A */
/*	calculates the best position for a number of stack B to be placed in stack A
	the best position should be bellow a smaller value and above a larger value
	this ensures the ascending order in stack A */

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
