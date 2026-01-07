#include "push_swap.h"

/*Rotaciona o topo com o final*/
void    *ft_rra_n_rrb(int *stack_x, int size)
{
    int contador;
    int temp;
    int *temp_stack;
    
    if (!stack_x || size < 2)
        return (NULL);
    //Aloca memória para uma stack temporária
    temp_stack = malloc(sizeof(int) * (size));
    if (!temp_stack)
        return (NULL);

    //Realiza a rotação
    contador = size - 1;
    while (contador > 0)
    {
        //Copia os elementos da stack original para a temporária, deslocando-os uma posição para baixo
        temp_stack[contador] = stack_x[contador - 1];
        contador--;
    }
    //Coloca o último elemento da stack original na primeira posição da temporária
    temp_stack[0] = stack_x[size - 1];

    //Copia os elementos da stack temporária de volta para a original
    contador = 0;
    while (contador < size)
    {
        stack_x[contador] = temp_stack[contador];
        contador++;
    }
    free(temp_stack);
    return (0);
}

void    *ft_rrr(int *stack_a, int *stack_b, int size_a, int size_b)
{
    ft_rra_n_rrb(stack_a, size_a);
    ft_rra_n_rrb(stack_b, size_b);
    return (0);
}