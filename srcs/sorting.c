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

int	calculate_cost(int index, int len)
{
	// If the number is on the first half
	// The cost of going to [0] is the index of the number int the stack
	// If it is after the half of the stack
	// The cost of going to [0] is the len - the index (rev rotate)
	if (index <= len / 2)
		return (index); // Cost if moving up
	else
		return (len - index); // Cost if moving down
}

int get_max_index(t_stack *stack)
{
	int max_index = 0;
	for (int i = 1; i < stack->len; i++)
	{
		if (stack->stack[i] > stack->stack[max_index])
			max_index = i;
	}
	return max_index;
}

int get_min_index(t_stack *stack)
{
	int min_index = 0;
	for (int i = 1; i < stack->len; i++)
	{
		if (stack->stack[i] < stack->stack[min_index])
			min_index = i;
	}
	return min_index;
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

int	position_in_stackb(t_stack *stack, int value)
{
	int max_index = get_max_index(stack);
	int min_index = get_min_index(stack); // Assume this function exists
	int i;

	// Handle the minimum value
	if (is_min(stack, value))
	{
		return min_index + 1;
	}

	// Handle the maximum value
	if (is_max(stack, value))
	{
		return max_index;
	}

	// General case: Find the correct position
	for (i = 0; i < stack->len - 1; i++)
	{
		if (stack->stack[i] > value && value > stack->stack[i + 1])
		{
			return i + 1;
		}
	}

	// If no correct position found, return the end of the stack
	return stack->len;
}

int	position_in_stacka(t_stack *stack, int value)
{
	int	min_index;
	int	max_index;
	int i;

	i = 0;
	min_index = get_min_index(stack);
	max_index = get_max_index(stack);
	if (is_min(stack, value))
	{
		return min_index;
	}
	if (is_max(stack, value))
	{
		return (max_index + 1) % stack->len;
	}
	for (int i = 0; i < stack->len - 1; i++)
	{
		if (stack->stack[i] < value && value < stack->stack[i + 1])
		{
			return i + 1;
		}
	}
	// If the value is greater than the max or smaller than the min
	return stack->len;
}

void find_cheapest(t_stack *stack_a, int *a_index, int *b_position)
{
	// Simplified version to just find the smallest element
	int min_index = 0;
	for (int i = 1; i < stack_a->len; i++)
	{
		if (stack_a->stack[i] < stack_a->stack[min_index])
			min_index = i;
	}
	// Position in stack_b (here, it's 0 since we're just simulating one element move)
	*a_index = min_index;
	*b_position = 0;
}

int	find_cheapeast(t_stack *stack_a, t_stack *stack_b, int *a_index, int *b_position)
{
	int	i;
	int	min_cost;

	i = 0;
	min_cost = INT_MAX;
	while (i < stack_a->len)
	{
		int value = stack_a->stack[i];
		int cost_a = calculate_cost(i, stack_a->len);
		int position_b = position_in_stackb(stack_b, value);
		int cost_b = calculate_cost(position_b, stack_b->len);
		int total_cost = cost_a + cost_b;

		if (total_cost < min_cost)
		{
			min_cost = total_cost;
			*a_index = i;
			*b_position = position_b;
		}
		i ++;
	}
	//printf("min-cost= %d\n", min_cost);
	return min_cost;
}

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

/* void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	min_index;

	i = 1;
	min_index = 0;
	while ((*stack_a)->len > 0)
	{
		i = 1;
		while (i < (*stack_a)->len)
		{
			if ((*stack_a)->stack[i] < (*stack_a)->stack[min_index])
				min_index = i;
			i ++;
		}
		while (min_index > 0)
		{
			ra(*stack_a);
			min_index--;
		}
		if(!is_sorted(*stack_a))
		{
			pb(stack_a, stack_b);
		}
		else
			break ;
	}
	while ((*stack_b)->len > 0)
	{
		pa(stack_a, stack_b);
	}
} */

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

void	reverse_sort_three(t_stack *s)
{
	if (s->stack[0] < s->stack[1] && (s->stack[2] < s->stack[0] && s->stack[2] < s->stack[1]))
		sb(s);
	else if ((s->stack[0] > s->stack[1] && s->stack[0] > s->stack[2]))
		sb(s);
	while (!is_revsorted(s))
	{
		rb(s);
		if ((s->stack[1] > s->stack[0] && s->stack[1] > s->stack[2])
			&& (s->stack[0] < s->stack[1] && s->stack[0] > s->stack[2]))
		{
			sb(s);
			break ;
		}
	}
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a)->len == 3)
	{
		sort_three(*stack_a);
		return;
	}
	else if ((*stack_a)->len == 2 && !is_sorted(*stack_a))
	{
		sa(*stack_a);
		return;
	}
	while ((*stack_a)->len > 3)
	{
		int min_index = get_min_index(*stack_a);
		if (min_index <= (*stack_a)->len / 2)
		{
			while (min_index-- > 0)
				ra(*stack_a);
		}
		else
		{
			while (min_index++ < (*stack_a)->len)
			{
				rra(*stack_a);
			}
		}
		//print_stacks(*stack_a, *stack_b);
		pb(stack_a, stack_b);
		//print_stacks(*stack_a, *stack_b);
	}
	sort_three(*stack_a);
	//print_stacks(*stack_a, *stack_b);
	while ((*stack_b)->len > 0)
	{
		int max_index = get_max_index(*stack_b);
		if (max_index <= (*stack_b)->len / 2)
		{
			while (max_index-- > 0)
				rb(*stack_b);
		}
		else
		{
			while (max_index++ < (*stack_b)->len)
				rrb(*stack_b);
		}
		pa(stack_a, stack_b);
		//print_stacks(*stack_a, *stack_b);
	}
}

void	move_element(t_stack **stack_a, t_stack **stack_b, int a_index, int b_position)
{
	if (a_index <= (*stack_a)->len / 2)
	{
		while (a_index-- > 0)
		{
			ra(*stack_a);
			//print_stacks(*stack_a, *stack_b);
		}
	}
	else
	{
		while (a_index++ < (*stack_a)->len)
		{
			rra(*stack_a);
			//print_stacks(*stack_a, *stack_b);
		}
	}
	if (b_position <= (*stack_b)->len / 2)
	{
		while (b_position-- > 0)
		{
			rb(*stack_b);
			//print_stacks(*stack_a, *stack_b);
		}
	}
	else
	{
		while (b_position++ < (*stack_b)->len)
		{
			rrb(*stack_b);
			//print_stacks(*stack_a, *stack_b);
		}
	}
	//print_stacks(*stack_a, *stack_b);
	pb(stack_a, stack_b);
	//print_stacks(*stack_a, *stack_b);
}

void	move_elementa(t_stack **stack_a, t_stack **stack_b, int a_index, int b_position)
{
	if (a_index <= (*stack_a)->len / 2)
	{
		while (a_index-- > 0)
		{
			ra(*stack_a);
			//print_stacks(*stack_a, *stack_b);
		}
	}
	else
	{
		while (a_index++ < (*stack_a)->len)
		{
			rra(*stack_a);
			//print_stacks(*stack_a, *stack_b);
		}
	}
	if (b_position <= (*stack_b)->len / 2)
	{
		while (b_position-- > 0)
		{
			rb(*stack_b);
			//print_stacks(*stack_a, *stack_b);
		}
	}
	else
	{
		while (b_position++ < (*stack_b)->len)
		{
			rrb(*stack_b);
			//print_stacks(*stack_a, *stack_b);
		}
	}
	//print_stacks(*stack_a, *stack_b);
	pa(stack_a, stack_b);
	//print_stacks(*stack_a, *stack_b);
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
		//return ;
	}
	// Now the max element is at the top of stack_b
	// Swap if the next element is smaller
	//printf("WHAT?\n");
	//if (stack_b->len > 1 && stack_b->stack[0] < stack_b->stack[1])
		//sb(stack_b);
}

int find_insert_position(t_stack *stack_a, int value)
{
	int pos = 0;
	while (pos < stack_a->len && stack_a->stack[pos] < value)
		pos++;
	return (pos);
}

void	insert_in_position(t_stack **stack_a, t_stack **stack_b)
{
	int	position;
	int	i;

	i = 0;
	//position = find_insert_position(*stack_a, (*stack_b)->stack[0]);
	position = position_in_stacka(*stack_a, (*stack_b)->stack[0]);
	if (position == 0)
	{
		pa(stack_a, stack_b);
		//ra(*stack_a);
		return ;
	}
	else if (position <= (*stack_a)->len / 2)
	{
		while (i < position)
		{
			ra(*stack_a);
			i ++;
		}
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

void	sort_large(t_stack **stack_a, t_stack **stack_b)
{
	//a_index is the index of the best number in stack a
	//b_position is the best position for the number in a_index
	int	a_index;
	int	b_position;

	while ((*stack_a)->len > 3)
	{
		find_cheapeast(*stack_a, *stack_b, &a_index, &b_position);
		move_element(stack_a, stack_b, a_index, b_position);
	}
	sort_three(*stack_a);
	sort_stack_b_descending(*stack_b);
	//print_stacks(*stack_a, *stack_b);
	while ((*stack_b)->len > 0)
	{
		insert_in_position(stack_a, stack_b);
		//print_stacks(*stack_a, *stack_b);
	}
	while (!is_sorted(*stack_a))
	{
		if (get_min_index(*stack_a) <= (*stack_a)->len / 2)
		{
			ra(*stack_a);
		}
		else
			rra(*stack_a);
		//print_stacks(*stack_a, *stack_b);
		//return ;
	}
	//print_stacks(*stack_a, *stack_b);
}
