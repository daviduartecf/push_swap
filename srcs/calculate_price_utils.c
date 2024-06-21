/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_price_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:56:56 by daduarte          #+#    #+#             */
/*   Updated: 2024/06/21 17:57:26 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int get_max_index(t_stack *stack)
{
	int	i;
	int max_index;

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

int get_min_index(t_stack *stack)
{
	int	i;
	int min_index;

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

