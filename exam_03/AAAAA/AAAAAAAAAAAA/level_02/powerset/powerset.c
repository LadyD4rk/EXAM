/* Allowed functions: atoi, printf, fprintf, malloc, calloc, realloc, free, stdout,
write */

#include <stdio.h>
#include <stdlib.h>

int	*create_array(char **av, int n)
{
	int		*array;
	int		i;

	array = malloc(sizeof(int *) * (n + 1));
	if (!array)
		return (NULL);
	i = 0;
	while (av[i])
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

int		check_limit(int *print, int limit, int x)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	while (i < x)
	{
		res = print[i] + res;
		i++;
	}
	if (res == limit)
		return (1);
	return (0);
}

void	powerset(int *array, int *print, int x, int x_print, int limit, int new_ac)
{
	int		i;

	if (x == new_ac)
		return ;
	else
	{
		i = x;
		if (check_limit(print, limit, x_print))
			print_array(print, x_print);
		while (i < new_ac)
		{
			print[x_print] = array[i];
			powerset(array, print, i + 1, x_print + 1, limit, new_ac);
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
	int		limit;
	
	if (ac < 3)
		return (1);
	limit = atoi(av[1]);
	new_ac = ac - 1;
	array = create_array(av + 2, new_ac);
	if (!array)
		return (1);
	print = calloc(new_ac, sizeof(int));
	powerset(array, print, 0, 0, limit, new_ac);
	free(print);
	free(array);
}
