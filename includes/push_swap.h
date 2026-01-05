#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>

typedef struct stack
{
    int *data;
    int size;
}   t_stack;

int main(int argc, char **argv);
void    *ft_sa_n_sb(int *stack_x);
void    *ft_pa_n_pb(int *stack_a, int *stack_b, char flag);
void    *ft_ra_n_rb(int *stack_x, int size);
void    *ft_rra_n_rrb(int *stack_x, int size);

#endif