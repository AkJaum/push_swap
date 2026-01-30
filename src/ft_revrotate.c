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

/*Rotaciona o topo com o final*/
void	ft_rra_n_rrb(int *stack_x, int size)
{
	int	tmp;
	int	i;

	if (!stack_x || size < 2)
		return ;
	tmp = stack_x[size - 1];
	i = size - 1;
	while (i > 0)
	{
		stack_x[i] = stack_x[i - 1];
		i--;
	}
	stack_x[0] = tmp;
	write(1, "rra\n", 4);
}
