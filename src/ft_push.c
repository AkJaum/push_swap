#include "push_swap.h"

void    ft_pa(int *stack_a, int *stack_b)
{
    int temp;

    if (!stack_a || !stack_b)
        return (0);
    //Troca o topo de stack_b com o topo de stack_a (falta implementar o shift dos elementos intermediários)
    temp = stack_b[0];
    stack_b[0] = stack_a[0];
    stack_a[0] = temp;
}

void   ft_pb(int *stack_a, int *stack_b)
{
    int temp;

    if (!stack_a || !stack_b)
        return (0);
    //Troca o topo de stack_a com o topo de stack_b (falta implementar o shift dos elementos intermediários)
    temp = stack_a[0];
    stack_a[0] = stack_b[0];
    stack_b[0] = temp;
}

//Função antiga (precisa de adaptação para funcionar corretamente)
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