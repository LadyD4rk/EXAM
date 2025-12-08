/* Allowed functions: atoi, printf, fprintf, malloc, calloc, realloc, free, stdout,
write */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	print_array(int *array, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		printf("%i", array[i]);
		if (i != len - 1)
			printf(" ");
		i++;
	}
}

int		*create_array(char **av, int limit)
{
	int		i;
	int		*array;

	i = 0;
	array = malloc(sizeof(int) * limit);
	if (!array)
		return (NULL);
	while (i < limit)
	{
		array[i] = atoi(av[i]);
		i++;
	}
	return (array);
}

void	

int		main(int ac, char **av)
{
	int		*array;
	int		*print;
	int		limit;
	int		num;
	
	if (ac < 3)
		return (1);
	limit = ac - 2;
	array = create_array(av + 2, limit);
	if (!array)
		return (1);
	print = malloc(sizeof(int) * limit);
	if (!print)
	{
		free(array);
		return (1);
	}
	num = atoi(av[1]);
	print_array(array, limit);
	return (0);
}
