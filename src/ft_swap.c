#include "push_swap.h"

void    *ft_move(int *stack_a, int *stack_b, int size, char flag)
{
}
/*Troca os dois primeiros argumentos de stack_x*/
int ft_sa_n_sb(int *stack_x)
{
    int temp;

    if (!stack_x && !stack_x[1])
        return (0);
    temp = stack_x[0];
    stack_x[0] = stack_x[1];
    stack_x[1] = temp;
    return (1);
}

/*Troca o topo de stack_x para o topo de stack_y*/
void    *ft_pa_n_pb(int *stack_a, int *stack_b, char flag)
{
    int temp;

    if (!stack_a || !stack_b)
        return (NULL);
    if (flag == 'a')
    {
        temp = stack_b[0];
        stack_b[0] = stack_a[0];
        stack_a[0] = temp;
    }
    else if (flag == 'b')
    {
        temp = stack_a[0];
        stack_a[0] = stack_b[0];
        stack_b[0] = temp;
    }
    return (0);
}

/*Rotaciona o topo com o final*/
void    *ft_ra_n_rb(int *stack_x, int size)
{
    int temp;
    
    if (!stack_x)
        return (NULL);
    temp = stack_x[0];
    stack_x[0] = stack_x[size - 1];
    stack_x[size - 1] = temp;
    return (0);
}

/*Rotate reverso (final com o topo)*/
void    *ft_rra_n_rrb(int *stack_x, int size)
{
    int temp;
    
    if (!stack_x)
        return (NULL);
    temp = stack_x[size - 1];
    stack_x[size - 1] = stack_x[0];
    stack_x[0] = temp;
    return (0);
}