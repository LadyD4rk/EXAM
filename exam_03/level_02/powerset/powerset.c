/* Allowed functions: atoi, printf, fprintf, malloc, calloc, realloc, free, stdout,
write */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	*create_array(char **av, int ac)
{
	int		n;
	int		*array;

	array = malloc(sizeof(int) * (ac + 1));
	if (!array)
		return (NULL);
	n = 0;
	while (n < ac)
	{
		array[n] = atoi(av[n]);
		n++;
	}
	return (array);
}

void	print_array(int *print, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		printf("%i", print[i]);
		if (i < n - 1)
			printf(" ");
		i++;
	}
	printf("\n");
}

int		count_array(int *print, int n, int value)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	while (i < n)
	{
		res = res + print[i];
		i++;
	}
	if (value == res)
		return (1);
	return (0);
}

void	powerset(int *array, int *print, int x, int x_print, int value, int limit)
{
	int		i;

	if (limit + 1 == x)
		return ;
	else
	{
		i = x;
		if (count_array(print, x_print, value))
		{
			print_array(print, x_print);
		}
		while (i < limit)
		{
			print[x_print] = array[i];
			powerset(array, print, i + 1, x_print + 1, value, limit);
			print[x_print] = 0;
			i++;
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
	value = atoi(av[1]);
	array = create_array(av + 2, new_ac);
	if (!array)
	return (1);
	print = calloc(new_ac, (sizeof(int)));
	powerset(array, print, 0, 0, value, new_ac);
	free(array);
	free(print);
	return (0);
}
