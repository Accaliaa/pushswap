/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdasser <zdasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 09:30:54 by zdasser           #+#    #+#             */
/*   Updated: 2022/03/20 21:01:01 by zdasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int check_dup(t_stack *a, int c, int i)
{
    int count;
   
    count = 0;
    while (i > 0)
    {
        if (a->stack[i - 1] == c)
            count++;
        i--;
    }
    return (count);
}

int check_alpha(char **argv, int argc)
{
    int i;
    int j;

    i = 1;
    while (i < argc)
    {
        j = 0;
        if (argv[i][j] == 0)
            return(0);
        while(argv[i][j])
        {
            if(argv[i][j] == '-') 
                j++;
            if(ft_isdigit(argv[i][j]) == 0)
                return(0);
            j++;
        }
        i++;
    }
    return(1);
}

int	ft_atoi(const char *str)
{
	int				n;
	unsigned long	nb;
	int				i;

	i = 0;
	n = 1;
	nb = 0;
	
    i = 0;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			n *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	if ((nb > 2147483647 && n == 1) || (nb > 2147483648 && n == -1))
        exit(ft_printf("Error\n"));
    return ((int)nb * n);
}

void check(char **argv, int argc, t_stack *a)
{
    int i;
    i = 0;

    if (!check_alpha(argv, argc))
        exit(ft_printf("Error\n"));
    while(i < argc - 1)
    {
        if(check_dup(a, ft_atoi(argv[i + 1]), i))
            exit(ft_printf("Error\n"));
        a->stack[i]= ft_atoi(argv[i + 1]);
        i++;
    }
    
}

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
    int count;

    count = 0;
    a = (t_stack *)malloc(sizeof(t_stack));
    b = (t_stack *)malloc(sizeof(t_stack));
    if(argc > 1)
    {
        a->stack = (int *)malloc(sizeof(int) * (argc - 1));
        b->stack = (int *)malloc(sizeof(int) * (argc - 1));
        a->stack_size = argc - 1;
        b->stack_size = 0;
        check(argv, argc, a); 
        a->data.arr = sort_array(a);
        check_sorted(a);
        ftcases(a, b, &count);
    }
    return(0);
}