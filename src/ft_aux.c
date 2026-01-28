#include "push_swap.h"

void	ft_normalizer(int *stack_a, int size)
{
	int	*tmp;
	int	i;
	int	j;
	int	count;

	tmp = malloc(sizeof(int) * size);
	if (!tmp)
		ft_handle_error(stack_a, tmp);
	i = 0;
	while (i < size)
	{
		tmp[i] = stack_a[i];
		i++;
	}
	i = 0;
	while (i < size)
	{
		count = 0;
		j = 0;
		while (j < size)
		{
			if (tmp[j] < tmp[i])
				count++;
			j++;
		}
		stack_a[i] = count;
		i++;
	}
	free(tmp);
}

int	ft_convert(const char *n, int *stack, int index)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;

	/* pular espaços */
	while (n[i] == ' ' || (n[i] >= 9 && n[i] <= 13))
		i++;

	/* tratar sinal */
	if (n[i] == '+' || n[i] == '-')
	{
		if (n[i] == '-')
			sign = -1;
		i++;
	}

	/* sinal sem número */
	if (n[i] == '\0')
		ft_handle_error(stack, NULL);

	/* conversão */
	while (n[i])
	{
		if (n[i] < '0' || n[i] > '9')
			ft_handle_error(stack, NULL);
		result = result * 10 + (n[i] - '0');
		if ((sign == 1 && result > INT_MAX)
			|| (sign == -1 && -result < INT_MIN))
			ft_handle_error(stack, NULL);
		i++;
	}

	stack[index] = (int)(result * sign);
	return (0);
}

void	ft_find_min_value(int *stack, int size)
{
	int	min_value;
	int	min_pos;
	int	i;

	min_value = stack[0];
	min_pos = 0;
	i = 1;
	while (i < size)
	{
		if (stack[i] < min_value)
		{
			min_value = stack[i];
			min_pos = i;
		}
		i++;
	}
	if (min_pos <= size / 2)
	{
		while (min_pos-- > 0)
		{
			ft_ra_n_rb(stack, size);
			printf("ra\n");
		}
	}
	else
	{
		while (min_pos++ < size)
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