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

void	ft_swap(int *stack_x, int size)
{
	int	temp;

	if (!stack_x || size < 2)
		ft_handle_error(stack_x, NULL, NULL);
	temp = stack_x[0];
	stack_x[0] = stack_x[1];
	stack_x[1] = temp;
	write(1, "sa\n", 3);
}
