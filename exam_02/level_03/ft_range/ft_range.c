#include <stdlib.h>

int		ft_len(int start, int end)
{
	int		i;

	i = 0;
	if (start == end)
		return(1);
	if (start < end)
	{
		while (start <= end)
		{
			start++;
			i++;
		}
		return(i);
	}
	if (start > end)
	{
		while (end <= start)
		{
			end++;
			i++;
		}
		return(i);
	}
	return (i);
}

int     *ft_range(int start, int end)
{
	int		*array;
	int		i;

	array = malloc(sizeof(int) * (ft_len(start, end) + 1));
	if (!array)
		return(NULL);
	i = 0;
	if (start <= end)
	{
		while(start + i <= end)
		{
			array[i] = start + i;
			i++;
		}
	}
	else
	{
		while (start - i >= end)
		{
			array[i] = start - i;
			i++;
		}
	}
	return(array);
}
