/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 10:50:52 by daduarte          #+#    #+#             */
/*   Updated: 2024/06/25 16:00:35 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a)->len == 3)
	{
		sort_three(*stack_a);
		return ;
	}
	else if ((*stack_a)->len == 2 && !is_sorted(*stack_a))
	{
		sa(*stack_a);
		return ;
	}
	else if ((*stack_a)->len > 3)
		sort_large(stack_a, stack_b);
}

/* SORT STACK == 3 */
/*	first case:		{3, 2, 1}
	second case:	{3, 1, 2}
	third case:		{1, 3, 2} or {2, 3, 1}
	forth case:		{2, 1, 3}
	ignored:		{1, 2, 3}
*/

void	sort_three(t_stack *s)
{
	if (s->stack[0] > s->stack[1] && s->stack[1] > s->stack[2])
	{
		sa(s);
		rra(s);
	}
	else if (s->stack[0] > s->stack[1] && s->stack[0] > s->stack[2])
	{
		ra(s);
		if (s->stack[0] > s->stack[1])
			sa(s);
	}
	else if (s->stack[1] > s->stack[0] && s->stack[1] > s->stack[2])
	{
		rra(s);
		if (s->stack[0] > s->stack[1])
			sa(s);
	}
	else if (s->stack[0] > s->stack[1])
		sa(s);
}

/* SORT STACK >3 */
/*	start pushing the cheapest number of stack A to B until stack 3 len == 3
	then sort the 3 numbers left in stack A
	the stack B is now with the numbers arranged in descending order
	find cheapest number in b to pass to stack B and push it to A
	finally check if A is sorted, if it is not, rotate until it is
		-a_index is the index of the best number in stack a
		-b_position is the best position for the number in a_index
		-b_index is the index of the best number in stack b
		-a_position is the best position for the number in b_index
*/

void	sort_large(t_stack **stack_a, t_stack **stack_b)
{
	int	a_index;
	int	b_index;
	int	b_position;
	int	a_position;

	while ((*stack_a)->len > 3)
	{
		cheapest(*stack_a, *stack_b, &a_index, &b_position);
		move_elem(stack_a, stack_b, a_index, b_position);
	}
	sort_three(*stack_a);
	while ((*stack_b)->len > 0)
	{
		cheapest_a(*stack_a, *stack_b, &b_index, &a_position);
		insert_elem(stack_a, stack_b, b_index, a_position);
	}
	while (!is_sorted(*stack_a))
	{
		if (get_min_index(*stack_a) <= (*stack_a)->len / 2)
			ra(*stack_a);
		else
			rra(*stack_a);
	}
}
