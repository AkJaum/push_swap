#include "push_swap.h"

/*Troca os dois primeiros argumentos de stack_x*/
void ft_swap(int *stack_x, int size)
{
    int temp;

    //Verifica se a stack é válida e tem pelo menos dois elementos
    if (!stack_x || size < 2)
        ft_handle_error(stack_x, NULL);
    //Realiza a troca dos dois primeiros elementos
    temp = stack_x[0];
    stack_x[0] = stack_x[1];
    stack_x[1] = temp;
    return ;
}

void ft_ss(int *stack_a, int size_a, int *stack_b, int size_b)
{
    ft_swap(stack_a, size_a);
    ft_swap(stack_b, size_b);
    return ;
}