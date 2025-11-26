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

void    *ft_check(char **argv, int *a, int argc)
{
    int i;
    
    i = 1;
    while (i < argc)
    {
        a[i - 1] = ft_atoi(argv[i]);
        i++;
    }
    return (0);
}

int main(int argc, char **argv)
{
    int *stack_a;
    int *stack_b;
    int i;

    stack_a = malloc(sizeof(int) * (argc - 1));
    stack_b = malloc(sizeof(int) * (argc - 1));
    if (!stack_a || !stack_b)
        return (1);
    ft_check(argv, stack_a, argc);
    i = 0;
    ft_pa_n_pb(stack_a, stack_b, 'b');
    while (i < argc - 1)
    {
        printf("%d ", stack_a[i]);
        printf("%d\n", stack_b[i]);
        i++;
    }
    free(stack_a);
    free(stack_b);
    return (0);
}
