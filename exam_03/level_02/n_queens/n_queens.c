/* Expected files : *.c *.h
Allowed functions : atoi, fprintf, write, calloc, malloc, free, realloc, stdout, stderr */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char	**create_table(int n)
{
	int		y;
	int		x;
	char	**table;

	table = malloc(sizeof(char *) * (n + 1));
	y = 0;
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
				if (y < value - 1)
				printf(" ");
					break ;
			}
			x++;
		}
		y++;
	}
	printf("\n");
}

void	free_double(char **table)
{
	int		y;

	y = 0;
	while(table[y])
	{
		free(table[y]);
		y++;
	}
	free(table);
}

int		check_diagonal(char **table, int x, int y, int add_x)
{
	int		new_x = x + add_x;
	int		new_y = y - 1;

	if (new_x < 0 || new_y < 0)
		return (1);
	if (table[new_y][new_x] == '1')
		return (0);
	if (table[new_y][new_x] == '\0')
		return (1);
	return (check_diagonal(table, new_x, new_y, add_x));
}

int		is_valid(char **table, int y, int x)
{
	int		i;

	i = y - 1;
	while (i >= 0)
	{
		if (table[i][x] == '1')
			return (0);
		i--;
	}
	return (check_diagonal(table, x, y, 1) && check_diagonal(table, x, y, -1));
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
			if (is_valid(table, y, x))
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
	n_queens(table, 0, value);
	free_double(table);
	return (0);
}
