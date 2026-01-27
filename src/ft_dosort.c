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

void	ft_sort_5(int *stack_a, int *size_a, int *stack_b, int *size_b)
{
	while (*size_a > 3)
	{
		ft_find_min_value(stack_a, *size_a);
		ft_push(stack_b, stack_a, size_b, size_a);
		printf("pb\n");
	}
	if (ft_is_sorted(stack_a, *size_a) == 1)
		ft_sort_2_n_3(stack_a, *size_a);
	while (*size_b > 0)
	{
		ft_push(stack_a, stack_b, size_a, size_b);
		printf("pa\n");
	}
}

void	ft_radix(int *stack_a, int *size_a, int *stack_b, int *size_b)
{
	int max_value;
	int max_bits;
	int bit;

	ft_normalizer(stack_a, *size_a);
	max_value = ft_find_max_value(stack_a, *size_a);
	max_bits = 0;
	while ((max_value >> max_bits) != 0)
		max_bits++;
	bit = 0;
	while (bit < max_bits)
	{
		int i = size_a[0];
		while (i--)
		{
			if (((stack_a[0] >> bit) & 1) == 0)
			{
				ft_push(stack_b, stack_a, size_b, size_a);
				printf("pb\n");
			}
			else if (((stack_a[0] >> bit) & 1) == 1)
			{
				ft_ra_n_rb(stack_a, *size_a);
				printf("ra\n");
			}
		}
		while (*size_b > 0)
		{
			ft_push(stack_a, stack_b, size_a, size_b);
			printf("pa\n");
		}
		bit++;
	}
	return ;
}