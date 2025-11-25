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

int main(int argc, char **argv)
{
    int *a;
    int *b;
    int i;
    
    i = 1;
    a = malloc(sizeof(int) * (argc - 1));
    b = malloc(sizeof(int) * (argc - 1));
    if (!a || !b)
        return (1);
    while (--i && argc > i)
        a[i] = ft_atoi(argv[i]);
    i = 0;
    while (i < argc - 1)
    {
        printf("%d\n", a[i]);
        i++;
    }
    free(a);
    return (0);
}
