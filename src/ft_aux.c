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
            ft_handle_error(stack, NULL);
		stack[index] = stack[index] * 10 + (n[i] - '0');
		i++;
    }
	stack[index] = stack[index] * sign;
	return (0);
}

void	ft_find_min_value(int *stack, int size)
{
	int	min_value;
    int min_pos;
	int	rotations;
	int	i;

	i = 0;
	min_value = stack[0];
	// Encontra o mínimo valor na stack
	while (i < size)
	{
		if (stack[i] < min_value)
			min_value = stack[i];
            min_pos = i;
		i++;
	}
	// Rotaciona até trazer o mínimo para o topo (stack[0])
	rotations = 0;

	while (stack[0] != min_value && rotations++ < size)
	{
        if (min_pos <= size/2)
        {
            ft_ra_n_rb(stack, size);
            printf("ra\n");
        }
        else
        {
		    ft_rra_n_rrb(stack, size);
		    printf("rra\n");
        }
	}
}

int ft_find_max_value(int *stack, int size)
{
	int	max_value;
	int	i;

	i = 0;
	max_value = stack[0];
	// Encontra o mínimo valor na stack
	while (i < size)
	{
		if (stack[i] > max_value)
			max_value = stack[i];
		i++;
	}
    return (max_value);
}