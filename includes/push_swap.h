#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

typedef struct stack
{
    int *data;
    int size;
}   t_stack;

int main(int argc, char **argv);
int ft_handle_error(void);
int ft_is_sorted(int *stack_a, int size);
void *ft_fillstack(char **argv, int *a, int argc);
int ft_swap(int *stack_x, int size);
void ft_sort_2_n_3(int *stack_a, int size);
void *ft_rra_n_rrb(int *stack_x, int size);
void *ft_ra_n_rb(int *stack_x, int size);
void    ft_find_min_value(int *stack, int size);
void    ft_sort_5(int *stack_a, int *size_a, int *stack_b, int *size_b);
void    ft_push(int *stack_dest, int *stack_src, int *size_dest, int *size_src);
void    ft_normalizer(int *stack_a, int size);
void    ft_radix(int *stack, int size);

#endif