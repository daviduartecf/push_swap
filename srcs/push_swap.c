/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 09:29:25 by daduarte          #+#    #+#             */
/*   Updated: 2024/06/25 16:33:09 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*stack_init(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
	{
		ft_printf("Memory allocation failed\n");
		exit(0);
	}
	stack->stack = NULL;
	stack->len = 0;
	return (stack);
}

void	free_stack_array(int **array_ptr)
{
	if (*array_ptr != NULL)
	{
		free(*array_ptr);
		*array_ptr = NULL;
	}
}

void	free_stacks(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a)
	{
		if (stack_a->len > 0)
			free_stack_array(&(stack_a->stack));
		stack_a->stack = NULL;
		free(stack_a);
		stack_a = NULL;
	}
	if (stack_b)
	{
		if (stack_b->len > 0)
			free_stack_array(&(stack_b->stack));
		stack_b->stack = NULL;
		free(stack_b);
		stack_b = NULL;
	}
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		exit(0);
	stack_a = stack_init();
	stack_b = stack_init();
	if (argc == 2)
		get_stack(stack_a, argv[1], &stack_a->len, stack_b);
	else
		parse_args(stack_a, argv, (argc - 1), stack_b);
	if (is_sorted(stack_a))
	{
		free_stacks(stack_a, stack_b);
		return (0);
	}
	if (stack_a->len > 1)
		sort_stack(&stack_a, &stack_b);
	free_stacks(stack_a, stack_b);
	return (0);
}
