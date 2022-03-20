/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdasser <zdasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 10:36:52 by zdasser           #+#    #+#             */
/*   Updated: 2022/03/20 21:10:56 by zdasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ftprintf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_data
{
	int *arr;
	int middle;
	int offset;
	int start;
	int end;
	int init_size;
	int down;
} t_data;

typedef struct s_stack
{
	int	*stack;
	int	stack_size;
	t_data data;
}	t_stack;


void	swap(t_stack *a);
void	push(t_stack *a, t_stack *b);
void	reverse_rotate(t_stack *a);
void	rotate(t_stack *a);
void	handle_three(t_stack *a);
void	handle_short(t_stack *a, t_stack *b, int *count);
int		ft_min(t_stack *a);
void	shift_down(t_stack *a);
int		*sort_array(t_stack *a);
void	check_place(int i, t_stack *a);
void	handle_long(t_stack *a, t_stack *b);
void	init_data(t_stack *a);
void	check_b(t_stack *a, t_stack *b);
void    ftcases(t_stack *a, t_stack *b, int *count);
int		ft_isdigit(int c);
void	check_sorted(t_stack *a);
#endif
