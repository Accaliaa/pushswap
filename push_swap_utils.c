/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdasser <zdasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:00:51 by zdasser           #+#    #+#             */
/*   Updated: 2022/03/15 18:43:14 by zdasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_min(t_stack *a)
{
	int	i;
	int	min;
	int tmp;

	i = 0;
	tmp = 0;
	min = a->stack[0];
	while(i < a->stack_size)
	{
		if(a->stack[i] < min)
		{
			min = a->stack[i];
			tmp = i;
		}
		i++;
	}
	return(tmp);
}

void	shift_down(t_stack *a)
{
	int i;

	i = a->stack_size;
	while(i > 0)
	{
		a->stack[i] = a->stack[i - 1];
		i--;
	}
}