#include "push_swap.h"

/*Rotaciona o topo com o final*/
void	ft_ra_n_rb(int *stack, int size)
{
	int	tmp;
	int	i;

	if (size < 2)
		return ;

	tmp = stack[0];
	i = 0;
	while (i < size - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[size - 1] = tmp;
}