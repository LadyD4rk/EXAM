/* Allowed functions: read, write, strlen, memmem, memmove, malloc, calloc,
realloc, free, printf, fprintf, stdout, stderr, perror */

#include <stdio.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	int		read_bytes;
	int		x_bytes;
	char	str[1000000];
	int		i;
	int		j;

	if (ac != 2)
		return (1);
	read_bytes = 0;
	x_bytes = 1;
	while (x_bytes > 0)
	{
		x_bytes = read(0, &str[read_bytes], 1);
		if (x_bytes < 0)
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
		{
			while (str[i + j] == av[1][j])
				j++;
		}
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
	printf("%s\n", str);
	return (0);
}