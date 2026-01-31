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
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct stack
{
	int	*data;
	int	size;
}	t_stack;

void	ft_convert(const char *n, int *stack, int index);
void	ft_fillstack(char **argv, int *a, int argc);
void	ft_convert_n_fillstack(char **argv, int *stack, int *size);
void	ft_swap(int *stack_x, int size);
void	ft_sort_2_n_3(int *stack_a, int size);
void	ft_rra_n_rrb(int *stack_x, int size);
void	ft_ra_n_rb(int *stack_x, int size);
void	ft_sort_5(int *stack_a, int *size_a, int *stack_b, int *size_b);
void	ft_push(int *stack_dest, int *stack_src, int *size_dest, int *size_src);
void	ft_normalizer(int *stack_a, int size);
void	ft_radix(int *stack_a, int *size_a, int *stack_b, int *size_b);
int		ft_handle_error(int *stack_a, int *stack_b);
int		ft_find_max_value(int *stack, int size);
int		ft_find_min_value(int *stack, int size);
int		ft_is_sorted(int *stack_a, int size);
int		ft_is_duplicated(int *stack, int size);

#endif
