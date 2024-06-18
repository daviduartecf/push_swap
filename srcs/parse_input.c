/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:24:50 by daduarte          #+#    #+#             */
/*   Updated: 2024/06/18 16:05:39 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_str_isdigit(char *str)
{
	int	i;
	long	number;

	i = 0;
	number = 0;
	if ((str[0] == '-' || str[0] == '+') && (str[1] >= '0' && str[1] <= '9'))
		i ++;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9'))
			i ++;
		else if ((str[i] == '-' || str[i] == '+'))
			return (0);
		else
			return (0);
	}
	number = ft_atol(str);
	if (number > INT_MAX || number < INT_MIN)
		return (0);
	return (1);
}

int	valid_arguments(int *stack, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (stack[i] == stack[j])
				return (0);
			else
				j ++;
		}
		i ++;
	}
	return (1);
}

void	get_stack_from_argument(t_stack *stack_a, char *argument, int *len, t_stack *stack_b)
{
	char	**argument_array;
	int		i;

	i = -1;
	argument_array = ft_split_and_len(argument, ' ', len);
	stack_a->stack = ft_calloc(stack_a->len, sizeof(int));
	if (stack_a->stack == NULL)
	{
		free(stack_a);
		exit(1);
	}
	while (++i < stack_a->len)
	{
		if (!ft_str_isdigit(argument_array[i]))
		{
			ft_putstr_fd("Error\n", 2);
			free_array(argument_array, *len);
			free_stacks(stack_a, stack_b);
			exit(1);
		}
		stack_a->stack[i] = ft_atoi(argument_array[i]);
	}
	if (!valid_arguments(stack_a->stack, stack_a->len))
	{
		ft_putstr_fd("Error\n", 2);
		free_array(argument_array, *len);
		free_stacks(stack_a, stack_b);
		exit(1);
	}
	free_array(argument_array, *len);
}
