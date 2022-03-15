/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdasser <zdasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 09:27:52 by zdasser           #+#    #+#             */
/*   Updated: 2022/03/14 22:07:56 by zdasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	swap(t_stack *a)
{
	int	i;
	
	i = a->stack[0];
    a->stack[0] = a->stack[1];
	a->stack[1] = i;
	ft_printf("sa \n");
}

void	push(t_stack *a, t_stack *b, int *count)
{
	int	i;
	
	(*count)++;
	i = 0;
	b->stack[0] = a->stack[0];
	while (i < a->stack_size)
	{
		a->stack[i] = a->stack[i + 1];
		i++;
	}
}

void	reverse_rotate(t_stack *a)
{
	int	i;
	int temp;
	
	i = a->stack_size - 1;
	temp = a->stack[a->stack_size - 1];
	while (i >= 0)
		{
			a->stack[i + 1] = a->stack[i];
			i--;
		}
	a->stack[0] = temp;
	ft_printf("rra \n");
}

void	rotate(t_stack *a)
{
	int	i;
	int temp;
	
	i = 1;
	temp = a->stack[0];
	while (i < a->stack_size)
		{
			a->stack[i - 1] = a->stack[i];
			i++;
		}
	a->stack[a->stack_size - 1] = temp;
	ft_printf("ra \n");
}
                                                                                                                                                            