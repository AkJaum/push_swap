#include "push_swap.h"

void    ft_push(int *stack_dest, int *stack_src, int *size_dest, int *size_src)
{
    int *temp;
    int i;

    if (!stack_dest || !stack_src)
        return ;
    if (*size_src == 0)
        return ;
    temp = malloc(sizeof(int) * (*size_dest + 1));
    if (!temp)
        return ;
    //Coloca o topo da stack_src no topo da stack_dest
    temp[0] = stack_src[0];
    i = 1;
    //Copia os elementos da stack_dest para a temporária, deslocando-os uma posição
    while (i < *size_dest)
    {
        temp[i] = stack_dest[i - 1];
        i++;
    }
    //Copia os elementos da temporária de volta para a stack_dest
    i = 0;
    while (i <= *size_dest)
    {
        stack_dest[i] = temp[i];
        i++;
    }
    (*size_dest)++;
    if (*size_src > 0)
    {
        //Remove o topo da stack_src, deslocando os elementos para baixo
        i = 0;
        while (i < *size_src - 1)
        {
            stack_src[i] = stack_src[i + 1];
            i++;
        }
        (*size_src)--;
    }
    free (temp);
    return ;
}