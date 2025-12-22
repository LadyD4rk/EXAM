/* Allowed functions: read, write, strlen, memmem, memmove, malloc, calloc,
realloc, free, printf, fprintf, stdout, stderr, perror */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char  **av)
{
	int		r;
	int		x;
	int		i;
	int		j;
	char	str[1000000];

	x = 1;
	r = 0;
	while (x > 0)
	{
		x = read(0, &str[r], 1);
		if (x < 0)
		{
			perror("Error: ");
			return (1);
		}
		r++;
	}
	str[r] = '\0';
	i = 0;
	while (str[i])
	{
		j = 0;
		if (str[i] == av[1][j])
			while (str[i + j] == av[1][j])
				j++;
		if (av[1][j] == '\0')
		{
			while (j > 0)
			{
				str[i] = '*';
				i++;
				j--;
			}
		}
		else
			i++;
	}
	printf("%s", str);
	return (0);
}
