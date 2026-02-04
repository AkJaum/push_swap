/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jneris-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:47:26 by jneris-d          #+#    #+#             */
/*   Updated: 2026/01/31 16:26:53 by jneris-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_handle_error(int *stack_a, int *stack_b, char **split)
{
	int	i;

	i = 0;
	write(2, "Error\n", 6);
	free(stack_a);
	free(stack_b);
	if (split != NULL)
	{
		while (split && split[i])
			free(split[i++]);
		free(split);
	}
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

void	ft_split_stack(char **argv, int **stack, int *size, int **stack_b)
{
	char	**numbers;
	int		i;

	numbers = ft_split(argv[1], ' ');
	i = 0;
	while (numbers && numbers[i])
		i++;
	if (!numbers || i == 0)
		ft_handle_error(*stack, *stack_b, numbers);
	free(*stack);
	free(*stack_b);
	*stack = malloc(sizeof(int) * i);
	*stack_b = malloc(sizeof(int) * i);
	if (!*stack || !*stack_b)
		ft_handle_error(*stack, *stack_b, numbers);
	i = 0;
	while (numbers[i])
	{
		if (ft_convert(numbers[i], *stack, i) == 1)
			ft_handle_error(*stack, *stack_b, numbers);
		i++;
	}
	*size = i;
	ft_is_duplicated(*stack, *size, *stack_b, numbers);
}

void	ft_fillstack(char **argv, int *stack, int argc, int *stack_b)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '\0')
			ft_handle_error(stack, stack_b, NULL);
		else
			if (ft_convert(argv[i], stack, i - 1) == 1)
				ft_handle_error(stack, stack_b, NULL);
		i++;
	}
	ft_is_duplicated(stack, argc - 1, stack_b, NULL);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc <= 1)
		return (0);
	stack_a.data = malloc(sizeof(int) * (argc - 1));
	stack_b.data = malloc(sizeof(int) * (argc - 1));
	if (!stack_a.data || !stack_b.data)
		ft_handle_error(stack_a.data, stack_b.data, NULL);
	stack_a.size = argc - 1;
	stack_b.size = 0;
	if (argc == 2)
		ft_split_stack(argv, &stack_a.data, &stack_a.size, &stack_b.data);
	else
		ft_fillstack(argv, stack_a.data, argc, stack_b.data);
	if (ft_is_sorted(stack_a.data, stack_a.size) == 0)
		return (free(stack_a.data), free(stack_b.data), 0);
	if (stack_a.size == 2 || stack_a.size == 3)
		ft_sort_2_n_3(stack_a.data, stack_a.size);
	else if (stack_a.size == 4 || stack_a.size == 5)
		ft_sort_5(stack_a.data, &stack_a.size, stack_b.data, &stack_b.size);
	else if (stack_a.size > 5)
		ft_radix(stack_a.data, &stack_a.size, stack_b.data, &stack_b.size);
	return (free(stack_a.data), free(stack_b.data), 0);
}
