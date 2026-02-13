/* Expected files : *.c *.h
Allowed functions : atoi, fprintf, write, calloc, malloc, free, realloc, stdout, stderr */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char	**create_table(int n)
{
	int		x;
	int		y;
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
				if (y < n - 1)
					printf(" ");
				break ;
			}
			x++;
		}
		y++;
	}
	printf("\n");
}

int		check_diagonal(char **table, int y, int x, int add_x)
{
	int		new_y = y - 1;
	int		new_x = x + add_x;

	if (new_x < 0 || new_y < 0)
		return (1);
	if (table[new_y][new_x] == '1')
		return (0);
	if (table[new_y][new_x] == '\0')
		return (1);
	return (check_diagonal(table, new_y, new_x, add_x));
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
	return (check_diagonal(table, y, x, 1) && check_diagonal(table, y, x, -1));
}

void	n_queens(char **table, int y, int n)
{
	int		x;

	if (y == n)
		print_table(table, n);
	else
	{
		x = 0;
		while (x < n)
		{
			if (is_valid(table, y, x))
			{
				table[y][x] = '1';
				n_queens(table, y + 1, n);
				table[y][x] = '0';
			}
			x++;
		}
	}
}

void	ft_free(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	main(int ac, char **av)
{
	char	**table;
	int		value;

	if (ac != 2)
		return (1);
	value = atoi(av[1]);
	table = create_table(value);
	n_queens(table, 0, value);
	ft_free(table);
	return (0);
}