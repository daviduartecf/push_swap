/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 09:29:25 by daduarte          #+#    #+#             */
/*   Updated: 2024/06/20 12:03:54 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	len = 0;

	i = 0;

	if (stack_a->len > stack_b->len)
		len = stack_a->len;
	else
		len =stack_b->len;
	while (i < len)
	{
		if (i < stack_a->len)
			ft_printf("%d  ", stack_a->stack[i]);
		else
			ft_printf("   ");
		if (i < stack_b->len)
			ft_printf("%d", stack_b->stack[i]);
		else
			ft_printf("   ");
		ft_printf("\n");
		i ++;
	}
	ft_printf("-- --\n");
}

t_stack	*stack_init()
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

void free_stack_array(int **array_ptr)
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

	stack_a = stack_init();
	stack_b = stack_init();
	if (argc == 1)
		exit(0);
	if (argc == 2)
	{
		get_stack_from_argument(stack_a, argv[1], &stack_a->len, stack_b);
	}
	else
	{
		ft_printf("Let's see!");
	}
	//print_stacks(stack_a, stack_b);
	if (stack_a->len <= 5)
		sort_stack(&stack_a, &stack_b);
	else if (stack_a->len > 5)
		sort_large(&stack_a, &stack_b);
	//ft_printf("\n");
	//print_stacks(stack_a, stack_b);
	free_stacks(stack_a, stack_b);
	return (0);
}
