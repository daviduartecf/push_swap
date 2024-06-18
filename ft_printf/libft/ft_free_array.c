/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 10:05:29 by daduarte          #+#    #+#             */
/*   Updated: 2024/06/18 10:05:38 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_array(char **array, int k)
{
	if (!array)
	{
		free(array);
		return ;
	}
	while (k >= 0)
	{
		free(array[k]);
		k --;
	}
	free(array);
}
