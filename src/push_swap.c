/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jneris-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:47:26 by jneris-d          #+#    #+#             */
/*   Updated: 2025/11/25 14:47:29 by jneris-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_handle_error(int *stack_a, int *stack_b)
{
	fprintf(stderr, "Error\n");
	free(stack_a);
	free(stack_b);
	exit(EXIT_FAILURE);
	return (1);
}

int	ft_is_sorted(int *stack_a, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (stack_a[i] > stack_a[i + 1])
			return (1);
		i++;
	}
	return (0);
}

void	*ft_fillstack(char **argv, int *stack, int argc)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '\0')
			ft_handle_error(stack, NULL);
		else
			ft_convert(argv[i], stack, i - 1);
		i++;
	}
	i = 0;
	while (i < argc - 1)
	{
		j = 0;
		while (j < argc - 1)
		{
			if (stack[i] == stack[j] && i != j)
				ft_handle_error(stack, NULL);
			j++;
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc <= 1)
		return (ft_handle_error(NULL, NULL));
	stack_a.data = malloc(sizeof(int) * (argc - 1));
	stack_b.data = malloc(sizeof(int) * (argc - 1));
	if (!stack_a.data || !stack_b.data)
		ft_handle_error(stack_a.data, stack_b.data);
	stack_a.size = argc - 1;
	stack_b.size = 0;
	ft_fillstack(argv, stack_a.data, argc);
	if (ft_is_sorted(stack_a.data, stack_a.size) == 0)
		return (free(stack_a.data), free(stack_b.data), 0);
	if (stack_a.size == 2 || stack_a.size == 3)
		ft_sort_2_n_3(stack_a.data, stack_a.size);
	else if (stack_a.size == 4 || stack_a.size == 5)
		ft_sort_5(stack_a.data, &stack_a.size, stack_b.data, &stack_b.size);
	else if (stack_a.size > 5)
		ft_radix(stack_a.data, &stack_a.size, stack_b.data, &stack_b.size);
	free(stack_a.data);
	free(stack_b.data);
	return (0);
}
