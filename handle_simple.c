/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_simple.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdasser <zdasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 18:21:56 by zdasser           #+#    #+#             */
/*   Updated: 2022/03/16 13:32:06 by zdasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	handle_three(t_stack *a)
{
	while(!(a->stack[0] < a->stack[1] && a->stack[1] < a->stack[2]))
	{
		
		if(a->stack[0] > a->stack[1] && a->stack[1] < a->stack[2] && a->stack[0] > a->stack[2])
			rotate(a);
		if(a->stack[0] < a->stack[1] && a->stack[1] > a->stack[2] && a->stack[2] < a->stack[0])
			reverse_rotate(a);
		if((a->stack[0] > a->stack[1]) ||  (a->stack[0] < a->stack[1] && a->stack[2] < a->stack[1]))
			swap(a);
		
	}
}

void	handle_short(t_stack *a, t_stack *b, int *count)
{
	int i;
	//ft_printf("i is:%d\n", a->stack_size);
	while(*count < a->stack_size - 3)
	{
		i = ft_min(a);
		//ft_printf("%i", i);
		
		if(i > a->stack_size/2)
		{
			while(i < a->stack_size)
			{
				reverse_rotate(a);
				i++;
			}
		}
		else if(i <= a->stack_size/2 && i)
		{
			while(i > 0)
			{
				rotate(a);
				i--;
			}
		}
		push(a , b);
		ft_printf("pb\n");
	}
	handle_three(a);
	while(b->stack_size > 0)
	{
		push(b, a);
		ft_printf("pa\n");
	}
		
}
