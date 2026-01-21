/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jneris-d <tbpjaum@outlook.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/00/00 00:00:00 by jneris-d          #+#    #+#             */
/*   Updated: 0000/00/00 00:00:00 by jneris-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_2_n_3(int *stack_a, int size)
{
	if (size == 2)
	{
		//Se os dois elementos estiverem fora de ordem, troca-os
		if (stack_a[0] > stack_a[1])
		{
			ft_swap(stack_a, size);
			printf("sa\n");
		}
	}
	else if (size == 3)
	{
		//Encontra qual é o maior elemento
		if (stack_a[0] > stack_a[1] && stack_a[0] > stack_a[2])
		{
			//Se o maior está no topo, rotaciona para trás
			ft_ra_n_rb(stack_a, size);
			printf("ra\n");
			if (stack_a[0] > stack_a[1])
			{
				ft_swap(stack_a, size);
				printf("sa\n");
			}
		}
		else if (stack_a[1] > stack_a[0] && stack_a[1] > stack_a[2])
		{
			//Se o maior está no meio, rotaciona para trás duas vezes
			ft_rra_n_rrb(stack_a, size);
			printf("rra\n");
			if (stack_a[0] > stack_a[1])
			{
				ft_swap(stack_a, size);
				printf("sa\n");
			}
		}
		else
		{
			//Se o maior está no final, só pode estar correto ou precisar de swap
			if (stack_a[0] > stack_a[1])
			{
				ft_swap(stack_a, size);
				printf("sa\n");
			}
		}
	}
}

void	ft_find_min_value(int *stack, int size)
{
	int	min_value;
	int	rotations;
	int	i;

	i = 0;
	min_value = stack[0];
	// Encontra o mínimo valor na stack
	while (i < size)
	{
		if (stack[i] < min_value)
			min_value = stack[i];
		i++;
	}
	// Rotaciona até trazer o mínimo para o topo (stack[0])
	rotations = 0;
	while (stack[0] != min_value && rotations < size)
	{
		ft_rra_n_rrb(stack, size);
		printf("rra\n");
		rotations++;
	}
}

void	ft_sort_5(int *stack_a, int *size_a, int *stack_b, int *size_b)
{
	ft_find_min_value(stack_a, *size_a);
	ft_push(stack_b, stack_a, size_b, size_a);
	printf("pb\n");
	ft_find_min_value(stack_a, *size_a);
	ft_push(stack_b, stack_a, size_b, size_a);
	printf("pb\n");
	ft_sort_2_n_3(stack_a, *size_a);
	while (*size_b > 0)
	{
		ft_push(stack_a, stack_b, size_a, size_b);
		printf("pa\n");
	}
}

void	ft_radix(int *stack, int size)
{
	ft_normalizer(stack, size);
	return ;
}