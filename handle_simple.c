/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_simple.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdasser <zdasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 18:21:56 by zdasser           #+#    #+#             */
/*   Updated: 2022/03/15 01:25:03 by zdasser          ###   ########.fr       */
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
	
	//i = ft_min(a);
	while(*count < a->stack_size - 3)
	{
		i = ft_min(a);
		//ft_printf("min: %d\n", i);
		push(a , b, count);
		ft_printf("pb \n");
	}
	// handle_three(a);
}
