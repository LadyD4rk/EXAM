#include <stdlib.h>
#include <stdio.h>

//just for debuging
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
	//updates the positon we are checking
	int	new_x = x + add_x;
	int	new_y = y + add_y;

	//if it is negative or \0 means it went out of bounds
	//without finding a queen
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
	//checks for any queens in the same collumn
	//eg
	//010
	//010
	//000
	//will return invalid
	for (int i = y - 1; i >= 0; i--)
	{
		if (table[i][x] == '1')
			return (0);
	}
	return (check_diagonals(table, x, y, -1, -1) && check_diagonals(table, x, y, 1, -1));
}


void print_result(char **arr)
{
	//print_table(arr);
	//printf("\n");
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
		//tries to place a queen in every x 
		//if it can it tries the next row
		//by calling the function again and then resets
		
		//eg (x being the one being tested)
		//x00 -> is valid thus goes to the next y
		//000
		//000

		//goes to the next row
		//100
		//x00 -> invalid thus tries the next x
		//000

		//next
		//100
		//0x0 -> invalid thus tries the next x
		//000

		//next
		//100
		//00x -> valid then goes to the next y
		//000

		//next
		//100
		//001
		//--- -> will always be invalid so the function goes up

		//next
		//100
		//000(x)-> is the null terminator so it goes "up"
		//000

		//next 
		//0x0 -> and does everything again
		//000
		//000


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

	//Alloc and fill table with 0
	//fill table with '0'
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