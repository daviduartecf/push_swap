/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 10:50:52 by daduarte          #+#    #+#             */
/*   Updated: 2024/06/20 17:57:35 by daduarte         ###   ########.fr       */
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

int	is_revsorted(t_stack *stack)
{
	int	i;

	i = 0;
	if (stack->len <= 1)
		return (1);
	while (i < stack->len - 1)
	{
		if (stack->stack[i] < stack->stack[i + 1])
		{
			return (0);
		}
		i ++;
	}
	return (1);
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

void	sort_stack(t_stack **stack_a)
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
}

int	position_in_stackb(t_stack *stack, int value)
{
	int i;
	int max_index;
	int min_index;

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
	// If no correct position found, return the end of the stack
	return (stack->len);
}

int	position_in_stacka(t_stack *stack, int value)
{
	int	min_index;
	int	max_index;

	min_index = get_min_index(stack);
	max_index = get_max_index(stack);
	if (is_min(stack, value))
		return (min_index);
	if (is_max(stack, value))
		return (max_index + 1);
	for (int i = 0; i < stack->len - 1; i++)
	{
		if (stack->stack[i] < value && value < stack->stack[i + 1])
			return (i + 1);
	}
	// If the value is greater than the max or smaller than the min
	return (stack->len);
}

void	handle_rotate_both(t_stack **stack_a, t_stack **stack_b, int *a_index, int *b_position)
{
	while (*a_index > 0 && *b_position > 0 && *a_index <= (*stack_a)->len / 2 && *b_position <= (*stack_b)->len / 2)
	{
		rr(*stack_a, *stack_b);
		(*a_index)--;
        (*b_position)--;
	}
	// Simultaneous reverse rotations
	while (*a_index < (*stack_a)->len && *b_position < (*stack_b)->len && *a_index > (*stack_a)->len / 2 && *b_position > (*stack_b)->len / 2)
	{
		rrr(*stack_a, *stack_b);
		(*a_index)++;
        (*b_position)++;
	}
}

void	move_element(t_stack **stack_a, t_stack **stack_b, int a_index, int b_position)
{
	handle_rotate_both(stack_a, stack_b, &a_index, &b_position);
	if (a_index <= (*stack_a)->len / 2)
	{
		while (a_index-- > 0)
			ra(*stack_a);
	}
	else
	{
		while (a_index++ < (*stack_a)->len)
			rra(*stack_a);
	}
	if (b_position <= (*stack_b)->len / 2)
	{
		while (b_position-- > 0)
			rb(*stack_b);
	}
	else
	{
		while (b_position++ < (*stack_b)->len)
			rrb(*stack_b);
	}
	pb(stack_a, stack_b);
}

void sort_stack_b_descending(t_stack *stack_b)
{
	while (!is_revsorted(stack_b))
	{
		// Find the maximum element and its position
		int max_index = 0;
		for (int i = 1; i < stack_b->len; i++)
		{
			if (stack_b->stack[i] > stack_b->stack[max_index])
				max_index = i;
		}
		// Bring the maximum element to the top
		if (max_index <= stack_b->len / 2)
		{
			while (max_index-- > 0)
				rb(stack_b);
		}
		else
		{
			while (max_index++ < stack_b->len)
				rrb(stack_b);
		}
		// After bringing the maximum to the top, push it down to its correct position
		if (!is_revsorted(stack_b))
		{
			rb(stack_b);
		}
	}
}

int find_insert_position(t_stack *stack_a, int value)
{
	int pos = 0;
	while (pos < stack_a->len && stack_a->stack[pos] < value)
		pos++;
	return (pos);
}
/*
void	insert_in_position(t_stack **stack_a, t_stack **stack_b)
{
	handle_rotate_both(stack_a, stack_b, &a_position, &b_index);
	
    if (b_index <= (*stack_b)->len / 2)
    {
        while (b_index-- > 0)
            rb(*stack_b);
    }
    else
    {
        while (b_index++ < (*stack_b)->len)
            rrb(*stack_b);
    }
    if (a_position <= (*stack_a)->len / 2)
    {
        while (a_position-- > 0)
            ra(*stack_a);
    }
    else
    {
        while (a_position++ < (*stack_a)->len)
            rra(*stack_a);
    }
    pa(stack_a, stack_b);
}*/

void	insert_in_position(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	position;

	i = -1;
	position = position_in_stacka(*stack_a, (*stack_b)->stack[0]);
	if (position == 0)
	{
		pa(stack_a, stack_b);
		return ;
	}
	else if (position <= (*stack_a)->len / 2)
	{
		while (++i < position)
			ra(*stack_a);
	}
	else if (position > (*stack_a)->len / 2)
	{
		i = (*stack_a)->len;
		while (i > position)
		{
			rra(*stack_a);
			i --;
		}
	}
	pa(stack_a, stack_b);
}

int find_cheapest_for_insertion(t_stack *stack_a, t_stack *stack_b, int *b_index, int *a_position)
{
    int i;
    t_cheapest cheapest;

    i = 0;
    cheapest.min_cost = INT_MAX;
    while (i < stack_b->len)
    {
        int pos_a = position_in_stacka(stack_a, stack_b->stack[i]);
        int cost_b = calculate_cost(i, stack_b->len);
        int cost_a = calculate_cost(pos_a, stack_a->len);
        int total_cost = cost_b + cost_a;

        if (total_cost < cheapest.min_cost)
        {
            cheapest.min_cost = total_cost;
            *b_index = i;
            *a_position = pos_a;
        }
        i++;
    }
    return cheapest.min_cost;
}

void insert_element(t_stack **stack_a, t_stack **stack_b, int b_index, int a_position)
{
    handle_rotate_both(stack_a, stack_b, &a_position, &b_index);
    if (b_index <= (*stack_b)->len / 2)
    {
        while (b_index-- > 0)
            rb(*stack_b);
    }
    else
    {
        while (b_index++ < (*stack_b)->len)
            rrb(*stack_b);
    }
    if (a_position <= (*stack_a)->len / 2)
    {
        while (a_position-- > 0)
            ra(*stack_a);
    }
    else
    {
        while (a_position++ < (*stack_a)->len)
            rra(*stack_a);
    }
    pa(stack_a, stack_b);
}

void	sort_large(t_stack **stack_a, t_stack **stack_b)
{
	//a_index is the index of the best number in stack a
	//b_position is the best position for the number in a_index
	int	a_index;
	int	b_position;

	while ((*stack_a)->len > 3)
	{
		find_cheapest(*stack_a, *stack_b, &a_index, &b_position);
		move_element(stack_a, stack_b, a_index, b_position);
	}
	sort_three(*stack_a);
	//sort_stack_b_descending(*stack_b);
	/*
	while ((*stack_b)->len > 0)
    {
        insert_in_position(stack_a, stack_b);
    }*/
	while ((*stack_b)->len > 0)
    {
        int b_index, a_position;
        find_cheapest_for_insertion(*stack_a, *stack_b, &b_index, &a_position);
        insert_element(stack_a, stack_b, b_index, a_position);
    }
	while (!is_sorted(*stack_a))
	{
		if (get_min_index(*stack_a) <= (*stack_a)->len / 2)
			ra(*stack_a);
		else
			rra(*stack_a);
	}
}
