/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 10:50:52 by daduarte          #+#    #+#             */
/*   Updated: 2024/06/25 10:59:46 by daduarte         ###   ########.fr       */
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

//a_index is the index of the best number in stack a
//b_position is the best position for the number in a_index
void	sort_large(t_stack **stack_a, t_stack **stack_b)
{
	int	a_index;
	int	b_index;
	int	b_position;
	int	a_position;

	while ((*stack_a)->len > 3)
	{
		find_cheapest(*stack_a, *stack_b, &a_index, &b_position);
		move_elem(stack_a, stack_b, a_index, b_position);
	}
	sort_three(*stack_a);
	while ((*stack_b)->len > 0)
	{
		find_cheapest_a(*stack_a, *stack_b, &b_index, &a_position);
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

/* MOVE ELEMENT FROM STACK A TO STACK B */
/*	first see if it is possible to rotate A and B
	then rotate stack A to put it index 0 the cheapest number
	then rotate stack B to prepare it to receive the number
	(it should be on top of the next largest number in stack B)
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
