#include "push_swap.h"

/*Troca os dois primeiros argumentos de stack_x*/
int ft_swap(int *stack_x)
{
    int temp;

    //Verifica se a stack é válida e tem pelo menos dois elementos
    if (!stack_x || !stack_x[1])
        return (0);
    //Realiza a troca dos dois primeiros elementos
    temp = stack_x[0];
    stack_x[0] = stack_x[1];
    stack_x[1] = temp;
    return (1);
}

int ft_ss(int *stack_a, int *stack_b)
{
    int res_a;
    int res_b;

    //Chama a função de swap para ambas as stacks
    res_a = ft_swap(stack_a);
    res_b = ft_swap(stack_b);
    if (res_a && res_b)
        return (1);
    return (0);
}