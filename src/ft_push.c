#include "push_swap.h"

void	ft_push(int *dst, int *src, int *size_dst, int *size_src)
{
	int	i;

	if (*size_src == 0)
		return ;

	i = *size_dst;
	while (i > 0)
	{
		dst[i] = dst[i - 1];
		i--;
	}
	dst[0] = src[0];
	(*size_dst)++;

	i = 0;
	while (i < *size_src - 1)
	{
		src[i] = src[i + 1];
		i++;
	}
	(*size_src)--;
}