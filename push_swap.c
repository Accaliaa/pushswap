/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdasser <zdasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 09:30:54 by zdasser           #+#    #+#             */
/*   Updated: 2022/03/19 16:35:57 by zdasser          ###   ########.fr       */
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
                {
                   // ft_printf("stack : %i , index ; %i \n", a->stack[i - 1], i - 1);
                    count++;
                }
        i--;
    }
    //ft_printf(" count :%i \n", count);
    return (count);
  
}

int check_alpha(char **str)
{
    int i;
    int j;

    i = 1;
    while (str[i])
    {
        j = 0;
        while(str[i][j])
        {
            if((str[i][j] <= 57 || str[i][j] >= 48) || str[i][j] == '-') 
                    j++;
            else
                return(0);
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
	if (n == 1 && nb > 9223372036854775807)
		return (-1);
	if (n == -1 && nb > 9223372036854775808u)
		return (0);
	return ((int)nb * n);
}

void check(char **argv, int argc, t_stack *a)
{
    int i;
    i = 0;

    if (!check_alpha(argv))
        {
            ft_printf("Error"); 
            exit(0);
        } 

    while(i < argc - 1)
    {
        if(check_dup(a, ft_atoi(argv[i + 1]), i))
            {
                ft_printf("Error"); 
                exit(0);
            }
            a->stack[i]= ft_atoi(argv[i + 1]);
            i++;
    }
}

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
    int k = 0;
    int count = 0;
    int *arr;

    a = (t_stack *)malloc(sizeof(t_stack));
    b = (t_stack *)malloc(sizeof(t_stack));
    if(argc > 1)
    {
    a->stack = (int *)malloc(sizeof(int) * (argc - 1));
    b->stack = (int *)malloc(sizeof(int) * (argc - 1));
    a->stack_size = argc - 1;
    b->stack_size = 0;
    check(argv, argc, a);
    //  int i = 0;
    // while(i < a->stack_size)
    // {
    //     ft_printf("%i\n", a->stack[i]);
    //     i++;
    // }
    init_data(a);
    handle_long(a , b);
  
    // k = 0;
    // ft_printf("\n");
    //  i = 0; 
    // while(i < a->stack_size)
    // {
    //     ft_printf(" \na : %i\n", a->stack[i]);
    //     i++;
    // }
    // i = 0;
    // while(i < b->stack_size)
    // {
    //     ft_printf(" \nb : %i\n", b->stack[i]);
    //     i++;
    // }
    }
    return(0);
}