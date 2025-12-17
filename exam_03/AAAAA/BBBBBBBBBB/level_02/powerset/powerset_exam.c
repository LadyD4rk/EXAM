/* Allowed functions: atoi, printf, fprintf, malloc, calloc, realloc, free, stdout,
write */

#include <stdlib.h>
#include <stdio.h>

int		*create_array(char **av, int n)
{
	int		*array;
	int		i;

	array = malloc(sizeof(int) * (n + 1));
	if (!array)
		return (NULL);
	i = 0;
	while (i < n)
	{
		array[i] = atoi(av[i]);
		i++;
	}
	return (array);
}

void	print_array(int *array, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		printf("%i", array[i]);
		if (i < n - 1)
			printf(" ");
		i++;
	}
	printf("\n");
}

int		check_array(int *array, int n, int value)
{
	int		i;
	int		total;

	i = 0;
	total = 0;
	while (i < n)
	{
		total = array[i] + total;
		i++;
	}
	if (total == value)
		return (1);
	return (0);
}

void	powerset(int *array, int *print, int x, int print_x, int limit, int value)
{
	int		i;
	
	if (x == limit + 1)
		return ;
	else
	{
		i = x;
		if (check_array(print, print_x, value))
		{
			print_array(print, print_x);
			return ;
		}
		while (i < limit)
		{
			print[print_x] = array[i];
			i++;
			powerset(array, print, i, print_x + 1, limit, value);
		}
	}
}

int	main(int ac, char **av)
{
	int		*array;
	int		*print;
	int		new_ac;
	int		value;

	new_ac = ac - 2;
	array = create_array(av + 2, new_ac);
	if (!array)
		return (1);
	print = calloc(new_ac + 1, sizeof(int));
	(void)print;
	value = atoi(av[1]);
	powerset(array, print, 0, 0, new_ac, value);
	free(array);
	free(print);
}
