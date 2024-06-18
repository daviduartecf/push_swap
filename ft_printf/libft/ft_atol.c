/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 09:04:15 by daduarte          #+#    #+#             */
/*   Updated: 2024/06/18 14:22:12 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

long	ft_atol(const char *str)
{
	int	i;
	int	neg;
	long	number;

	i = 0;
	neg = 1;
	number = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i ++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i ++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + (str[i] - '0');
		i ++;
	}
	return (number * neg);
}
