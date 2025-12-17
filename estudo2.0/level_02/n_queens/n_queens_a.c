/* atoi, fprintf, write, calloc, malloc, free, realloc, stdout, stderr */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	free_table(char **table)
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

char	**create_table(int n)
{
	char	**table;
	int		x;
	int		y;

	table = malloc(sizeof(char *) * (n + 1));
	if (!table)
		return (NULL);
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

void	print_table(char **table, int n)
{
	int		y;
	int		x;

	y = 0;
	while (table[y])
	{
		x = 0;
		while(table[y][x])
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

int	check_diagonal(char **table, int y, int x, int n)
{
	int		left = x - 1;
	int		right = x + 1;

	if (y < 0 || x < 0 || x >= n)
        return (1);
	if (table[y][x] == '\0')
		return (1);
	if (table[y][x] == '1')
		return (0);
	if (table[y][x] == '0')
		return (1);
	return (check_diagonal(table, y, left, n) && check_diagonal(table, y, right, n));
}

int		valid_queen(char **table, int y, int x, int n)
{
	int		i;

	i = y;
	while (i > 0)
	{
		if (table[i][x] == '1')
			return (0);
		i--;
	}
	return (check_diagonal(table, y - 1, x - 1, n) && check_diagonal(table, y - 1, x + 1, n));
}

void	start_table(char **table, int y, int n)
{
	int		x;	

	if (table[y] == NULL)
		print_table(table, n);
	else
	{
		x = 0;
		while (table[y][x])
		{
			if (valid_queen(table, y, x, n))
			{
				table[y][x] = '1';
				start_table(table, y + 1, n);
				table[y][x] = '0';
			}
			x++;
		}
	}
}

int	main(int ac, char **av)
{
	int		n;
	char	**table;

	if (ac != 2)
		return (1);
	n = atoi(av[1]);
	table = create_table(n);
	if (!table)
		return (1);
	start_table(table, 0, n);
	free_table(table);
	return (0);
}
