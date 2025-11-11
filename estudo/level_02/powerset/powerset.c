#include <stdio.h>
#include <stdlib.h>

int	*create_array(int ac, char **av)
{
	int		*array;
	int		i;

	array = malloc(sizeof(int) * ac);
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

void	print_array(int *array, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		printf("%i", array[i]);
		if (i + 1 < len)
			printf(" ");
		i++;
	}
}

int	add_array(int *print, int num, int len)
{
	int		res;
	int		i;
	int		aux;

	i = 0;
	res = 0;
	while (i < len)
	{
		aux = print[i];
		res = res + aux;
		i++;
	}
	if (res == num)
		return (1);
	return (0);
}

void	power(int *array, int *print, int start, int print_index, int total, int len)
{	
	int 	i;
	int		num;

	if (start >= len)
		return ;
	i = start;
	while (i < len)
	{
		num = array[i];
		print[print_index] = num;
		if (add_array(print, total, print_index + 1))
		{
			print_array(print, print_index + 1);
			printf("\n");
		}
		power(array, print, i + 1, print_index + 1, total, len);
		i++;
	}
}

int main(int ac, char **av)
{
	int		num;
	int		*array;
	int		*print;
	
	if (ac < 2)
		return (1);
	num	= atoi(av[1]);
	array = create_array(ac - 2, &av[2]);
	if (!array)
		return (1);
	print = malloc(sizeof(int) * (ac - 2));
	if (!print)
		return(1);
	power(array, print, 0, 0, num, ac - 2);
	free(array);
	free(print);
}
