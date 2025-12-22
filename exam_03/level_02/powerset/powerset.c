/* Expected files   : *.c *.h
Allowed functions: atoi, printf, fprintf, malloc, calloc, realloc, free, stdout,
write */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		*create_array(int n, char **av)
{
	int		*array;
	int		i;

	i = 0;
	array = malloc(sizeof(int) * (n + 1));
	while (i < n)
	{
		array[i] = atoi(av[i]);
		i++;
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

int		is_check(int *print, int x, int value)
{
	int		res;
	int		i;

	i = 0;
	res = 0;
	while (i < x)
	{
		res = res + print[i];
		i++;
	}
	if (res == value)
		return (1);
	return (0);
}

void	powerset(int *array, int *print, int x, int print_x, int value, int limit)
{
	int		i;

	if (x == limit)
		return ;
	else
	{
		if (is_check(print, print_x, value))
			print_array(print, print_x);
		i = x;
		while (i < limit - 1)
		{
			print[print_x] = array[i];
			powerset(array, print, i + 1, print_x + 1, value, limit);
			print[print_x] = 0;
			i++;
		}
	}
}

int	main(int ac, char **av)
{
	int		*array;
	int		*print;
	int		new_ac;

	new_ac = ac - 2;
	array = create_array(new_ac, av + 2);
	print = calloc(new_ac, (sizeof(int)));
	powerset(array, print, 0, 0, atoi(av[1]), new_ac + 1);
	free(array);
	free(print);
	return (0);
}