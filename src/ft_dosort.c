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
		if (stack_a[0] > stack_a[1])
			ft_swap(stack_a, size);
	}
	else if (size == 3)
	{
		if (stack_a[0] > stack_a[1] && stack_a[0] > stack_a[2])
		{
			ft_ra_n_rb(stack_a, size);
			if (stack_a[0] > stack_a[1])
				ft_swap(stack_a, size);
		}
		else if (stack_a[1] > stack_a[0] && stack_a[1] > stack_a[2])
		{
			ft_rra_n_rrb(stack_a, size);
			if (stack_a[0] > stack_a[1])
				ft_swap(stack_a, size);
		}
		else
			ft_swap(stack_a, size);
	}
}

void	ft_sort_5(int *stack_a, int *size_a, int *stack_b, int *size_b)
{
	int	min_pos;

	while (*size_a > 3)
	{
		min_pos = ft_find_min_value(stack_a, *size_a);
		if (min_pos <= *size_a / 2)
		{
			while (min_pos-- > 0)
				ft_ra_n_rb(stack_a, *size_a);
		}
		else
		{
			while (min_pos++ < *size_a)
				ft_rra_n_rrb(stack_a, *size_a);
		}
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

//31 linhas
void	ft_radix(int *stack_a, int *size_a, int *stack_b, int *size_b)
{
	int	max_value;
	int	max_bits;
	int	bit;
	int	i;

	ft_normalizer(stack_a, *size_a);
	max_value = ft_find_max_value(stack_a, *size_a);
	max_bits = 0;
	while ((max_value >> max_bits) != 0)
		max_bits++;
	bit = 0;
	while (bit < max_bits)
	{
		i = *size_a;
		while (i--)
		{
			if (((stack_a[0] >> bit) & 1) == 0)
			{
				ft_push(stack_b, stack_a, size_b, size_a);
				printf("pb\n");
			}
			else
				ft_ra_n_rb(stack_a, *size_a);
		}
		while (*size_b > 0)
		{
			ft_push(stack_a, stack_b, size_a, size_b);
			printf("pa\n");
		}
		bit++;
	}
}
