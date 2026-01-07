#include "push_swap.h"

/*Rotaciona o topo com o final*/
void    *ft_ra_n_rb(int *stack_x, int size)
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
    contador = 0;
    while (contador < size - 1)
    {
        //Copia os elementos da stack original para a temporária, deslocando-os uma posição para cima
        temp_stack[contador] = stack_x[contador + 1];
        contador++;
    }
    //Coloca o primeiro elemento da stack original na última posição da temporária
    temp_stack[size - 1] = stack_x[0];
    
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

void    *ft_rr(int *stack_a, int *stack_b, int size_a, int size_b)
{
    ft_ra_n_rb(stack_a, size_a);
    ft_ra_n_rb(stack_b, size_b);
    return (0);
}