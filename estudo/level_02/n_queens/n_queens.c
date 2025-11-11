#include <stdlib.h>
#include <stdio.h>

/* 
	! Allowed functions : atoi, fprintf, write, calloc, malloc, free, realloc, stdout, stderr 
*/

void	print_table(char **table, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		printf("%s\n", table[i]);
		i++;
	}
}

void	free_table(char **table, int size)
{
	int		i;
	
	if (!table)
		return ;
	i = 0;
	while (i < size)
	{
		free(table[i]);
		i++;
	}
	free(table);
}

char	**create_table(int size)
{
	char	**table;
	int		x;
	int		y;

	table = calloc(size + 1, sizeof(char *));
	if (!table)
		return (NULL);
	y = 0;
	while (y < size)
	{
		table[y] = calloc(size + 1, 1);
		if (!table[y])
		{
			free_table(table, y);
			return (NULL);
		}
		x = 0;
		while (x < size)
		{
			table[y][x] = '0';
			x++;
		}
		table[y][x] = '\0';
		y++;
	}
	table[y] = NULL;
	return (table);
}

int	main(int ac, char **av)
{
	char	**table;
	int		size;
	
	if (ac != 2)
		return (1);
	size =  atoi(av[1]);
	if (size <= 3)
		return (1);
	table = create_table(size);
	if (!table)
		return (1);
	print_table(table, size);
	free_table(table, size);
	return (0);
}
