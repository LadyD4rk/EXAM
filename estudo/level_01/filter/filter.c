#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int		main(int ac, char **av)
{
	int		x_bytes;
	int		read_bytes;
	char	str[1000000]; // string com informações
	int		i; // andar na string
	int		j; // check de tamanho

	read_bytes = 0;
	x_bytes = 1;
	if (ac != 2)
		return (1);
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
