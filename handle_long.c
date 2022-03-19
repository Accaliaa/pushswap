/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_long.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdasser <zdasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:38:01 by zdasser           #+#    #+#             */
/*   Updated: 2022/03/19 18:13:18 by zdasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	offset(t_stack *a)
{
	if(a->stack_size <= 10)
		a->data.offset = a->stack_size / 2;
	else if(a->stack_size <= 150)
		a->data.offset = a->stack_size / 8;
	else if(a->stack_size > 150)
		a->data.offset = a->stack_size / 18;
}
void init_data(t_stack *a)
{
	a->data.init_size = a->stack_size;
	a->data.arr = sort_array(a);
	offset(a);
	a->data.middle = a->stack_size / 2;
	a->data.start = a->data.middle - a->data.offset;
	a->data.end = a->data.middle + a->data.offset;
}

void ft_compare(t_stack *a, t_stack *b)
{
	if(a->stack[0] >= a->data.arr[a->data.start] \
				&& a->stack[0] <= a->data.arr[a->data.end - 1])
			{
				push(a, b);
				ft_printf("pb\n");
				if (b->stack[0] < a->data.arr[a->data.middle] && b->stack_size > 1)
				{
					rotate(b);
					ft_printf("rb\n");
				}
			}
			else
			{
				rotate(a);
				ft_printf("ra\n");
			}
}

void		handle_long(t_stack *a, t_stack *b)
{
	int i;
	int	j;

	i = a->data.offset * 2;
	j = 0;
	while(a->stack_size > 0)
	{
		i = a->data.end - a->data.start;
		while (b->stack_size < i && a->stack_size > 0)
		{
			ft_compare(a, b);
		}
		if (a->data.start - a->data.offset < 0)
			a->data.start = 0;
		else
			a->data.start -= a->data.offset;
		if (a->data.end + a->data.offset > a->data.init_size)
			a->data.end = a->data.init_size;	
		else
			a->data.end += a->data.offset;
	}
}