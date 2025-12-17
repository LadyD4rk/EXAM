/* Allowed functions : atoi, fprintf, write, calloc, malloc, free, realloc, stdout, stderr */

#include <stdlib.h>
#include <stdio.h>

char	**create_table(int n)
{
	int		y;
	int		x;
	char	**table;

	table = malloc(sizeof(char *) * (n + 1));
	if (!table)
		return (NULL);
	y = 0;
	while (y < n)
	{
		table[y] = malloc(sizeof(char) * (n + 1));
		x = 0;
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

void	free_double(char **table)
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

void	print_table(char **table, int value)
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
				if (y < value)
					printf(" ");
				break ;
			}
			x++;
		}
		y++;
	}
	printf("\n");
}

int		check_diagonal(char **table, int y, int x, int add_y, int add_x)
{
	int		new_x = x + add_x;
	int		new_y = y + add_y;

	if (new_y < 0 || new_x < 0)
		return (1);
	if (table[new_y][new_x] == '1')
		return (0);
	if (table[new_y][new_x] == '\0')
		return (1);
	return (check_diagonal(table, new_y, new_x, add_y, add_x));
}

int		is_valid(char **table, int x, int y)
{
	int		i;

	i = y - 1;
	while (i >= 0)
	{
		if (table[i][x] == '1')
			return (0);
		i--;
	}
	return (check_diagonal(table, y, x, -1, -1) && check_diagonal(table, y, x, -1, 1));
}

void	n_queens(char **table, int y, int value)
{
	int		x;

	if (table[y] == NULL)
		print_table(table, value);
	else
	{
		x = 0;
		while (table[y][x])
		{
			if (is_valid(table, x, y))
			{
				table[y][x] = '1';
				n_queens(table, y + 1, value);
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
	//print_table(table);
	n_queens(table, 0, value);
	free_double(table);
	return (0);
}