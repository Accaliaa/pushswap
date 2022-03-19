/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdasser <zdasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:00:51 by zdasser           #+#    #+#             */
/*   Updated: 2022/03/19 16:38:08 by zdasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	i = a->stack_size - 1;
	while(i > 0)
	{
		a->stack[i] = a->stack[i - 1];
		i--;
	}
}
void	ft_fill(t_stack *a, int *arr)
{
	int	i;

	i = -1;
	while(++i< a->stack_size)
		arr[i] = a->stack[i];
}

int	*sort_array(t_stack *a)
{

	int j;
	int min;
	int tmp;
	int *arr;

	j = 0;
	min = -1; 
	arr = (int *)malloc(sizeof(int) * a->stack_size);
	
	ft_fill(a, arr);
	while(++min < a->stack_size)
	{
		j = min;
		while(++j < a->stack_size)
		{
			if(arr[min] > arr[j])
			{
				tmp = arr[min];
				arr[min] = arr[j];
				arr[j] = tmp;
			}
		}
	}
	return(arr);
}

void	check_place(int i, t_stack *a)
{
	
		if(i > a->stack_size/2)
		{
			while(i < a->stack_size)
			{
				reverse_rotate(a);
				ft_printf("rra\n");
				i++;
			}
		}
		else if(i <= a->stack_size/2 && i)
		{
			while(i > 0)
			{
				rotate(a);
				ft_printf("ra\n");
				i--;
			}
		}
}