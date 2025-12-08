#include <stdio.h>
#include <unistd.h>

/* ! Allowed functions: read, write, strlen, memmem, memmove, malloc, calloc,
realloc, free, printf, fprintf, stdout, stderr, perror */

int		main(int ac, char **av)
{
	char	str[1000000];
	int		read_bytes;
	int		check;
	int		i;
	int		j;

	if (ac != 2)
		return (1);
	check = 1;
	read_bytes = 0;
	while (check > 0)
	{
		check = read(0, &str[read_bytes], 1);
		if (check < 0)
		{
			perror("Error: ");
			return (1);
		}
		read_bytes++;
	}
	str[read_bytes] = '\0';
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
				j--;
				i++;
			}
		}
		else
			i++;
	}
	printf("%s", str);
	return (0);
}
