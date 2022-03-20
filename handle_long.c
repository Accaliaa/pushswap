/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_long.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdasser <zdasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:38:01 by zdasser           #+#    #+#             */
/*   Updated: 2022/03/20 20:49:24 by zdasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	btoa(t_stack *a, t_stack *b, int *i, int j)
{
	if (b->stack[0] == a->data.arr[*i])
	{
		push(b, a);
		ft_printf("pa\n");
		(*i)--;
	}
	else if (a->data.down == 0 || b->stack[0] > a->stack[a->stack_size - 1])
	{
		push(b, a);
		ft_printf("pa\n");
		rotate(a);
		ft_printf("ra\n");
		a->data.down++;
	}
	else
	{
		if (j <= b->stack_size / 2)
		{
			rotate(b);
			ft_printf("rb\n");
		}
		else if (j > b->stack_size / 2)
		{
			reverse_rotate(b);
			ft_printf("rrb\n");
		}
	}
}

int	getindex(t_stack *stack, int big)
{
	int	i;

	i = 0;
	while (i < stack->stack_size)
	{
		if (stack->stack[i] == big)
			return (i);
		i++;
	}
	return (-1);
}

void	check_b(t_stack *a, t_stack *b)
{
	int	i;
	int	j;
	
	i = a->data.init_size - 1;
    a->data.down = 0;
	while (b->stack_size || a->data.down)
	{
		j = getindex(b, a->data.arr[i]);
		if (j >= 0)
		{
			btoa(a, b, &i, j);
		}
		else if (a->data.down && a->stack_size > 1)
		{
			reverse_rotate(a);
			ft_printf("rra\n");
			i--;
			a->data.down--;
		}
	}
}

void	offset(t_stack *a)
{
	if (a->stack_size <= 10)
		a->data.offset = a->stack_size / 2;
	else if (a->stack_size <= 150)
		a->data.offset = a->stack_size / 8;
	else if (a->stack_size > 150)
		a->data.offset = a->stack_size / 18;
}

void init_data(t_stack *a)
{
	a->data.init_size = a->stack_size;
	offset(a);
	a->data.middle = a->stack_size / 2;
	a->data.start = a->data.middle - a->data.offset;
	a->data.end = a->data.middle + a->data.offset;
}

void ft_compare(t_stack *a, t_stack *b)
{
	if (a->stack[0] >= a->data.arr[a->data.start] \
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
	while (a->stack_size > 0)
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
	check_b(a, b);
}
