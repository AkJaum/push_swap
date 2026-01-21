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
    while(i < size)
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
    free(stack_temp);
    return ;
}

int ft_convert(const char *n, int *stack, int index)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while ((n[i] >= 9 && n[i] <= 13))
	    i++;
	if (n[i] == '+' || n[i] == '-')
	{
		if (n[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (n[i] != '\0')
	{
	    if (n[i] < '0' || n[i] > '9')
            ft_handle_error();
		stack[index] = stack[index] * 10 + (n[i] - '0');
		i++;
    }
	stack[index] = stack[index] * sign;
	return (0);
}