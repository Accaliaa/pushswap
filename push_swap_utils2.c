#include "push_swap.h"

void handle_two(t_stack	*a)
{
	if(a->stack_size == 1)
		exit(0);
    if(a->stack_size == 2)
    {
        if(a->stack[0] > a->stack[1])
        {
            rotate(a);
            ft_printf("ra\n");
        }
        else
            exit(0);
    }
}


void    ftcases(t_stack *a, t_stack *b, int *count)
{
	if(a->stack_size < 3)
		handle_two(a);
    if(a->stack_size == 3)
        handle_three(a);
    else if(a->stack_size > 3 && a->stack_size <= 5)
        handle_short(a, b, count);
    else if(a->stack_size > 5)
    {   init_data(a);
        handle_long(a, b);
    }
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

void    check_sorted(t_stack *a)
{
    int i;

    i = 0;
    while(i < a->stack_size && a->stack[i] == a->data.arr[i])
        i++;
    if(i == a->stack_size)
        exit(0);
}
