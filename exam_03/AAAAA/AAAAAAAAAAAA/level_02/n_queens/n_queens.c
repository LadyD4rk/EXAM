// Allowed functions : atoi, fprintf, write, calloc, malloc, free, realloc, stdout, stderr

#include <stdlib.h>
#include <stdio.h>

void	clear_table(char **table)
{
	int		i;

	i = 0;
	while (table[i])
	{
		free(table[i]);
		i++;
	}
	free(table);
}

void	print_table(char **table, int n)
{	
	int		y;
	int		x;

	y = 0;
	while (table[y])
	{
		x = 0;
		while (table[y][x])
		{
			if (table[y][x] == '1')
			{
				printf("%i", x);
				if (x < n)
					printf(" ");
				break ;
			}
			x++;
		}
		y++;
	}
	printf("\n");
}

char	**create_table(int n)
{
	char	**table;
	int		y;
	int		x;

	y = 0;
	table = malloc(sizeof(char *) * (n + 1));
	if (!table)
		return (NULL);
	while (y < n)
	{
		x = 0;
		table[y] = malloc(sizeof(char) * (n + 1));
		while (x < n)
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

int		check_diagonal(char **table, int y, int x, int n)
{
	int		left = x - 1;
	int		right = x + 1;

	if (y < 0 || x < 0 || x >= n)
		return (1);
	if (table[y][x] == '1')
		return (0);
	if (table[y][x] == '0')
		return (1);
	if (table[y][x] == '\0')
		return (1);
	return (check_diagonal(table, y, left, n) && check_diagonal(table, y, right, n));
}

int		is_valid(char **table, int y, int x, int n)
{
	int		i;

	i = y;
	while (i >= 0)
	{
		if (table[i][x] == '1')
			return (0);
		i--;
	}
	return (check_diagonal(table, y - 1, x - 1, n) && check_diagonal(table, y - 1, x + 1, n));
}

void	n_queens(char **table, int y, int n)
{
	int		x;
	
	if (table[y] == NULL)
		print_table(table, n);
	else
	{
		x = 0;
		while (table[y][x])
		{
			if (is_valid(table, y, x, n))
			{
				table[y][x] = '1';
				n_queens(table, y + 1, n);
				table[y][x] = '0';
			}
			x++;
		}
	}
}

int	main(int ac, char **av)
{
	char	**table;
	int		value;
	
	if (ac != 2)
		return (1);
	value = atoi(av[1]);
	table = create_table(value);
	if (!table)
		return (1);
	n_queens(table, 0, value);
	clear_table(table);
	return (0);
}