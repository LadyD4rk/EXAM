/* Allowed functions: atoi, printf, fprintf, malloc, calloc, realloc, free, stdout,
write */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int		*create_array(char **av, int n)
{
	int		i;
	int		*array;

	array = malloc (sizeof(int) * (n + 1));
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

int		check_print(int *print, int n, int value)
{
	int		i;
	int 	res;

	i = 0;
	res = 0;
	while (i < n)
	{
		res = res + print[i];
		i++;
	}
	if (res == value)
		return (1);
	return (0);
}

void	powerset(int *array, int *print, int x, int x_print, int value, int limit)
{
	int		i;

	if (x == limit)
		return ;
	else
	{
		if (check_print(print, x_print, value))
			print_array(print, x_print);
		i = x;
		while (i < limit - 1)
		{
			print[x_print] = array[i];
			powerset(array, print, i + 1, x_print + 1, value, limit);
			print[x_print] = 0;
			i++;
		}
	}
}

int		main(int ac, char **av)
{
	int		*array;
	int		*print;
	int		value;
	int		new_ac;

	if (ac < 3)
		return (1);
	new_ac = ac - 2;
	value = atoi(av[1]);
	array = create_array(av + 2, new_ac);
	print = calloc(new_ac, sizeof(int));
	powerset(array, print, 0, 0, value, new_ac);
	free(array);
	free(print);
	return (0);
}