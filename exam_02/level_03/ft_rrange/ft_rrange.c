#include <stdlib.h>

int		ft_len(int start, int end)
{
	int		i;

	if (start == end)
		return(1);
	if (start < end)
	{
		while (start + i <= end)
			i++;
		return (i);
	}
	else
	{
		while(end + i <= start)
			i++;
		return (i);
	}
	return (i);
}

int     *ft_rrange(int start, int end)
{
	int		*array;
	int		i;

	array = malloc(sizeof(int) * (ft_len(start, end) + 1));
	if (!array)
		return (NULL);
	i = 0;
	if (end <= start)
	{
		while (end + i <= start)
		{
			array[i] = end + i;
			i++;
		}
	}
	else
	{
		while (end - i >= start)
		{
			array[i] = end - i;
			i++;
		}
	}
	return (array);
}
