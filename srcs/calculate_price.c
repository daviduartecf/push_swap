/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_price.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:55:56 by daduarte          #+#    #+#             */
/*   Updated: 2024/06/25 10:40:49 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_cheapest(t_stack *stack_a, t_stack *stack_b, int *a_index, int *b_pos)
{
	int			i;
	t_cheapest	cheapest;

	i = 0;
	cheapest.min_cost = INT_MAX;
	while (i < stack_a->len)
	{
		cheapest.value = stack_a->stack[i];
		cheapest.cost_a = calculate_cost(i, stack_a->len);
		cheapest.position = position_in_stackb(stack_b, cheapest.value);
		cheapest.cost_b = calculate_cost(cheapest.position, stack_b->len);
		cheapest.total_cost = cheapest.cost_a + cheapest.cost_b;
		if (cheapest.total_cost < cheapest.min_cost)
		{
			cheapest.min_cost = cheapest.total_cost;
			*a_index = i;
			*b_pos = cheapest.position;
		}
		i ++;
	}
	return (cheapest.min_cost);
}

int	find_cheapest_a(t_stack *stack_a, t_stack *stack_b, int *b_ind, int *a_pos)
{
	int			i;
	t_cheapest	cheapest;

	i = 0;
	cheapest.min_cost = INT_MAX;
	while (i < stack_b->len)
	{
		cheapest.position = position_in_stacka(stack_a, stack_b->stack[i]);
		cheapest.cost_b = calculate_cost(i, stack_b->len);
		cheapest.cost_a = calculate_cost(cheapest.position, stack_a->len);
		cheapest.total_cost = cheapest.cost_b + cheapest.cost_a;
		if (cheapest.total_cost < cheapest.min_cost)
		{
			cheapest.min_cost = cheapest.total_cost;
			*b_ind = i;
			*a_pos = cheapest.position;
		}
		i++;
	}
	return (cheapest.min_cost);
}

// If the number is on the first half
// The cost of going to [0] is the index of the number int the stack
// If it is after the half of the stack
// The cost of going to [0] is the len - the index (rev rotate)
int	calculate_cost(int index, int len)
{
	if (index <= len / 2)
		return (index);
	else
		return (len - index);
}
