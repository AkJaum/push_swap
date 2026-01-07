int ft_move(int *stack_x, int size, int position, int wpos)
{
    int temp;
    int i;

    if (!stack_x || size <= 1)
        return (0);
    while (position != wpos)
    {
        if (position < wpos)
        {
            i = position;
            temp = stack_x[position];
            while (position < wpos)
            {
                stack_x[position] = stack_x[position + 1];
                position++;
            }
            stack_x[wpos] = temp;
        }
        else if (position > wpos)
        {
            i = position;
            temp = stack_x[position];
            while (position > wpos)
            {
                stack_x[position] = stack_x[position - 1];
                position--;
            }
            stack_x[wpos] = temp;
        }
    }
}