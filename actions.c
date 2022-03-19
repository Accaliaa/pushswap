/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdasser <zdasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 09:27:52 by zdasser           #+#    #+#             */
/*   Updated: 2022/03/19 16:37:01 by zdasser          ###   ########.fr       */
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

void	push(t_stack *a, t_stack *b)
{
	int	i;

	i = 1;
	b->stack_size++;
	shift_down(b);
	b->stack[0] = a->stack[0];
	
	while (i < a->stack_size)
	{
		a->stack[i - 1] = a->stack[i];
		i++;
	}
	a->stack[a->stack_size - 1] = 0;
	a->stack_size--;
	i = 0;
	while(i < a->stack_size)
    {
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
}
                                                                                                                                                            