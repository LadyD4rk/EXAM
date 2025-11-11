#include <stdlib.h>
#include <stdio.h>

void print_table(char **table)
{
	for (int h = 0; table[h] != NULL; h++)
		printf("%s\n", table[h]);
}

void free_arr(char **arr)
{
	if (arr == NULL)
		return ;
	for (int i = 0; arr[i] != NULL; i++)
		free(arr[i]);
	free(arr);
}

int check_diagonals(char **table, int x, int y, int add_x, int add_y)
{
	int	new_x = x + add_x;
	int	new_y = y + add_y;

	if (new_y < 0 || new_x < 0)
		return (1);
	if (table[new_y][new_x] == '\0')
		return (1);
	if (table[new_y][new_x] == '1')
		return (0);
	return (check_diagonals(table, new_x, new_y, add_x, add_y));
}

int is_valid(char **table, int x, int y)
{
	for (int i = y - 1; i >= 0; i--)
	{
		if (table[i][x] == '1')
			return (0);
	}
	return (check_diagonals(table, x, y, -1, -1) && check_diagonals(table, x, y, 1, -1));
}

void print_result(char **arr)
{
	for(int i = 0; arr[i] != NULL; i++)
	{
		for(int h = 0; arr[i][h] != '\0'; h++)
		{
			if(arr[i][h] == '1')
				printf("%d",h);
		}
		if (arr[i + 1] != NULL)
			printf(" ");
	}
	printf("\n");
}

void n_queens(char **arr, int y)
{
	if (arr[y] == NULL)
		print_result(arr);
	else
	{
		for (int x = 0; arr[y][x] != '\0'; x++)
		{
			if (is_valid(arr, x, y))
			{
				arr[y][x] = '1';
				n_queens(arr, y + 1);
				arr[y][x] = '0';
			}
		}
	}
	
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	int	size = atoi(argv[1]);

	char **table  = calloc(size + 1, sizeof(char *));
	if (table == NULL)
		return (0);
	for (int i = 0; i < size; i++)
	{
		table[i] = calloc(size + 1, 1);
		if (table[i] == NULL)
			return (free_arr(table), 0);
		for (int h = 0; h < size; h++)
			table[i][h] = '0';
	}
	table[size] = NULL;
	n_queens(table, 0);
	free_arr(table);
	return(0);
}
