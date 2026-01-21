#include "push_swap.h"

void ft_normalizer(int *stack_a, int size)
{
    int *stack_temp;
    int i;
    
    stack_temp = malloc(sizeof(int) * size);
    if (!stack_temp)
        return ;
    //Copiando os valores da stack_a para a stack_temp
    i = 0;
    while(1 < size)
    {
        stack_temp[i] = stack_a[i];
        i++;
    }
    i = 0;
    while (i < size)
    {
        int j = 0;
        int count = 0;
        while (j < size)
        {
            if (stack_a[i] > stack_temp[j])
                count++;
            j++;
        }
        stack_a[i] = count;
        i++;
    }
    i = 0;
    while (i < size)
    {
        printf("%d ", stack_a[i]);
        i++;
    }
    return ;
}