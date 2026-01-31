/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jneris-d <tbpjaum@outlook.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/00/00 00:00:00 by jneris-d          #+#    #+#             */
/*   Updated: 2026/01/31 16:25:52 by jneris-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_normalizer(int *stack_a, int size)
{
	int	*tmp;
	int	i;
	int	j;
	int	count;

	tmp = malloc(sizeof(int) * size);
	if (!tmp)
		ft_handle_error(stack_a, NULL);
	i = -1;
	while (++i < size)
		tmp[i] = stack_a[i];
	i = -1;
	while (++i < size)
	{
		count = 0;
		j = -1;
		while (++j < size)
			if (tmp[j] < tmp[i])
				count++;
		stack_a[i] = count;
	}
	free(tmp);
}

void	ft_convert(const char *n, int *stack, int index)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (n[i] == ' ' || (n[i] >= 9 && n[i] <= 13))
		i++;
	if (n[i] == '+' || n[i] == '-')
		if (n[i++] == '-')
			sign = -1;
	if (n[i] < '0' || n[i] > '9')
		ft_handle_error(stack, NULL);
	while (n[i] >= '0' && n[i] <= '9')
	{
		result = result * 10 + (n[i] - '0');
		if ((sign == 1 && result > INT_MAX)
			|| (sign == -1 && result * -1 < INT_MIN))
			ft_handle_error(stack, NULL);
		i++;
	}
	if (n[i])
		ft_handle_error(stack, NULL);
	stack[index] = (int)(result * sign);
}

int	ft_find_min_value(int *stack, int size)
{
	int	min_value;
	int	min_pos;
	int	i;

	min_value = stack[0];
	min_pos = 0;
	i = 0;
	while (i < size)
	{
		if (stack[i] < min_value)
		{
			min_value = stack[i];
			min_pos = i;
		}
		i++;
	}
	return (min_pos);
}

int	ft_find_max_value(int *stack, int size)
{
	int	max_value;
	int	i;

	i = 0;
	max_value = stack[0];
	while (i < size)
	{
		if (stack[i] > max_value)
			max_value = stack[i];
		i++;
	}
	return (max_value);
}

int	ft_is_duplicated(int *stack, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (stack[i] == stack[j])
				ft_handle_error(stack, NULL);
			j++;
		}
		i++;
	}
	return (0);
}
