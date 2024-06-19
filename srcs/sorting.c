/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 10:50:52 by daduarte          #+#    #+#             */
/*   Updated: 2024/06/19 16:55:52 by daduarte         ###   ########.fr       */
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
			return (0);
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
		sa(s);
	else if (s->stack[0] > s->stack[1] && s->stack[1] == 1)
		sa(s);
	while (!is_sorted(s))
	{
		rra(s);
		if (s->stack[1] == 1 && s->stack[0] == 2)
		{
			sa(s);
			break ;
		}
	}
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

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	max_index;
	int	min_index;

	i = 1;
	max_index = 0;
	min_index = 0;
	if ((*stack_a)->len == 3)
		sort_three(*stack_a);
	else if ((*stack_a)->len == 2 && !is_sorted(*stack_a))
		sa(*stack_a);
	if (is_sorted(*stack_a))
		return ;
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	reverse_sort_three(*stack_b);
	while ((*stack_a)->len > 0)
	{
		i = 1;
		min_index = 0;
		while (i < (*stack_a)->len)
		{
			if ((*stack_a)->stack[i] < (*stack_a)->stack[min_index])
				min_index = i;
			i ++;
		}
		while (min_index > 0 && min_index < (*stack_a)->len / 2)
		{
			ra(*stack_a);
			min_index--;
		}
		while (min_index >= (*stack_a)->len / 2 && min_index < (*stack_a)->len)
		{
			rra(*stack_a);
			min_index++;
		}
		if(!is_sorted(*stack_a) || (*stack_a)->len > 0)
		{
			pb(stack_a, stack_b);
			if (!is_revsorted(*stack_b))
				rb(*stack_b);
		}
		else
			break ;
	}
	while ((*stack_b)->len > 0)
	{
		if (!is_max(*stack_b, (*stack_b)->stack[0]))
		{
			int max_index = get_max_index(*stack_b);
			while (max_index > 0 && max_index < (*stack_b)->len / 2)
			{
				rb(*stack_b);
				max_index--;
			}
			while (max_index >= (*stack_b)->len / 2 && max_index < (*stack_b)->len)
			{
				rrb(*stack_b);
				max_index++;
			}
		}
		pa(stack_a, stack_b);
	}
}
