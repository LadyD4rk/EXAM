#include <stdio.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	int		x;
	int		r;
	int		i;
	int		j;
	char	str[1000000];

	r = 0;
	x = 1;
	if (ac != 2)
		return (1);	
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
