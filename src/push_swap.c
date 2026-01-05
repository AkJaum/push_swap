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
    t_stack stack_a;
    t_stack stack_b;
    int i;

    stack_a.data = malloc(sizeof(int) * (argc - 1));
    stack_b.data = malloc(sizeof(int) * (argc - 1));
    if (!stack_a.data || !stack_b.data)
        return (1);
    stack_a.size = argc - 1;
    stack_b.size = 0;
    ft_check(argv, stack_a.data, argc);
    free(stack_a.data);
    free(stack_b.data);
    return (0);
}
