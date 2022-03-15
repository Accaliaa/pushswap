/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdasser <zdasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 10:36:52 by zdasser           #+#    #+#             */
/*   Updated: 2022/03/14 22:07:32 by zdasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>


typedef struct s_stack
{
	int	*stack;
	int	stack_size;
}	t_stack;

void	swap(t_stack *a);
void	push(t_stack *a, t_stack *b, int *count);
void	reverse_rotate(t_stack *a);
void	rotate(t_stack *a);
// char	**ft_split(char const *s, char c);
// char	*ft_substr(char const *s, unsigned int start, size_t len);
void	handle_three(t_stack *a);
void	handle_short(t_stack *a, t_stack *b, int *count);
int		ft_min(t_stack *a);
#endif