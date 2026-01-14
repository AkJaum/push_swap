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

int    ft_handle_error(void)
{
    //Função para tratar erros de entrada
    fprintf(stderr, "Error\n");
    exit(EXIT_FAILURE);
    return (1);
}

int    ft_is_sorted(int *stack_a, int size)
{
    int i;

    i = 0;
    //Loop para checar se a stack está ordenada ou se há números repetidos
    while (i < size - 1)
    {
        if (stack_a[i] > stack_a[i + 1])
            return (1);
        if (stack_a[i] == stack_a[i + 1])
            ft_handle_error();
        i++;
    }
    return (0);
}

void    *ft_fillstack(char **argv, int *a, int argc)
{
    int i;
    
    i = 1;
    //Preenchendo stack_a com os valores de entrada
    while (i < argc)
    {
        a[i - 1] = ft_atoi(argv[i]);
        i++;
    }
    return (0);
}

int main(int argc, char **argv)
{
    //Declarando stacks
    t_stack stack_a;
    t_stack stack_b;

    //Checando erros na entrada, depois precisa ser adaptada junto da função de checar se há repetidos ou se há coisas além de números (daria erro na atoi)
    if (argc <= 1)
        return (ft_handle_error());
    
    //Alocando memória para as stacks (data) e definindo seus tamanhos (size)
    stack_a.data = malloc(sizeof(int) * (argc - 1));
    stack_b.data = malloc(sizeof(int) * (argc - 1));
    if (!stack_a.data || !stack_b.data)
        return (1);
    
    stack_a.size = argc - 1;
    stack_b.size = 0;

    //Preenchendo stack_a com os valores de entrada
    ft_fillstack(argv, stack_a.data, argc);
    //Checando se já está ordenado
    if (ft_is_sorted(stack_a.data, stack_a.size) == 0)
        return (free(stack_a.data), free(stack_b.data), 0);
    //Ordenar baseado no tamanho da stack
    if (stack_a.size == 2)
        ft_sort_2_n_3(stack_a.data, stack_a.size);
    else if (stack_a.size == 3)
        ft_sort_2_n_3(stack_a.data, stack_a.size);
    else if (stack_a.size <= 5)
        ft_sort_5(stack_a.data, &stack_a.size, stack_b.data, &stack_b.size);
    // Não imprimir a stack aqui; stdout deve conter apenas movimentos válidos
    free(stack_a.data);
    free(stack_b.data);
    return (0); 
}
