/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isdigit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:02:52 by daduarte          #+#    #+#             */
/*   Updated: 2024/06/25 16:11:57 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_isdigit(char *str)
{
	int		i;
	long	number;

	i = 0;
	number = 0;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9')
			|| (str[i] == '-' || str[i] == '+'))
		{
			i ++;
		}
		else
			return (0);
	}
	number = ft_atoi(str);
	if (number > 2147483647 || number < -2147483648)
		return (0);
	return (1);
}
